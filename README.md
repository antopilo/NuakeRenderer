# NuakeRenderer
NuakeRenderer is a simple library for OpenGL. It provides a simple abstraction over the most popular OpenGL concepts like Framebuffers, Textures, VertexBuffers, Shaders, etc.

## How to build
Simply add this repository as a submodule or clone it in your project and include the folder in your CMake. Make sure you add the directory in your includes folder.

## How to use
After including the NuakeRenderer/Window.h header

You can create a window with a title and some size
```cpp
#include <NuakeRenderer/Window.h>

void main()
{
  using namespace NuakeRenderer;
  auto window = Window("My window", Vector2(1280, 720));

  while(!window.ShouldClose())
  {
    NuakeRenderer::Begin();
    // do rendering.
    window.SwapBuffers();
  }
}
```
