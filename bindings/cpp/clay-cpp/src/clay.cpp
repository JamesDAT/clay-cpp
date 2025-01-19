#include <clay/clay.hpp>

#define CLAY_IMPLEMENTATION
#include <clay.h>

namespace clay {
	void Initialize(const Dimensions& dimensions, std::function<void(ErrorData)> errorCallback) {
		uint64_t totalMemorySize = Clay_MinMemorySize();
		Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(totalMemorySize, new char[totalMemorySize]);

		// TODO fill out the rest of the error data once ErrorData struct is completed
		std::function<void(Clay_ErrorData)> errorForwarder = [&](Clay_ErrorData clayErrorData) {
			ErrorData errorData;
			errorData.errorString = clayErrorData.errorText.chars;
			errorCallback(errorData);
		};

		Clay_Initialize(clayMemory, Clay_Dimensions{ dimensions.width, dimensions.height }, Clay_ErrorHandler {errorForwarder.target<void(Clay_ErrorData)>()});
	}

	void Initialize(const Dimensions& errorData) {
		Initialize(errorData, [](ErrorData) {}); // call into Initialize without any error callback
	}

	void BeginLayout() {
		Clay_BeginLayout();
	}

	void EndLayout() {
		Clay_EndLayout();
	}

	void Create(std::function<void()> function) {
		Clay__OpenElement();

		Clay__AttachElementConfig(Clay_ElementConfigUnion{ .rectangleElementConfig = Clay__StoreRectangleElementConfig((Clay__Clay_RectangleElementConfigWrapper{ { .color = { 255,255,255,0 } } }).wrapped) }, CLAY__ELEMENT_CONFIG_TYPE_RECTANGLE);

		function();
		Clay__CloseElement();

		Clay_Arena arena;
	}
}