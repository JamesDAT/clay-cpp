#include <iostream>
#include <clay/clay.hpp>


// basic test for current features of clay-cpp
// this is used for development of the binding
// itself rather than a true example of how to use it
int main() {
    clay::Initialize({ 1000, 500 });

    

    clay::BeginLayout();

    clay::Create([]() {
            
    });

    clay::EndLayout();

    return 0;
}