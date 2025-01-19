#pragma once
#include <functional>
#include <string>

namespace clay {
	enum class ErrorType {

	};

	struct ErrorData {
		ErrorType errorType;
		std::string errorString;
		uintptr_t userData;
	};

	struct Dimensions {
		float width, height;
	};

	/// @brief Initialize Clay and it's memory
	/// @param Dimensions Struct (Width, Height)
	/// @param Error callback ( void(std::string) )
	void Initialize(const Dimensions&, std::function<void(ErrorData)>);
	void Initialize(const Dimensions&);

	void BeginLayout();
	void EndLayout();

	/// @brief create a layout element (Equivalent to Clay macro)
	/// @param takes a void function, give it a lambda to give the
	/// same effect as using the Clay macro, call create again within
	/// the lambda to create a child element
	void Create(std::function<void()>);
	
}