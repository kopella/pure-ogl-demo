# 【基础】OpenGL 学习笔记：OpenGL 的初始化方法 (Windows)

在正式使用 OpenGL 之前， 我们必须先初始化它。OpenGL 为了保证平台无关性，并没有提供一个标准的初始化方法，每一个平台的处理方法都有一些不同。本篇笔记记录了 OpenGL 在 Windows 平台的初始化方法，并完成了一个简单的三角形 Demo。

实际上相关的笔记在互联网上已经太多太多了，所以我尝试整了点不太一样的，即不引入第三方库，纯手动初始化 OpenGL。（不过其实这种笔记在互联网上也已经太多了）

## 环境

Windows 11, VS Code, CMake, Clang.

## 流程

OpenGL 的初始化流程可分为两部分：第一部分是为 OpenGL 创建上下文(Context)，第二部分是加载需要使用的 OpenGL 函数。

### 为 OpenGL 创建上下文 (Context)

在一般的 Demo 中， 这是像 GLFW 这样的库所完成的工作。OpenGL 的上下文为可以看作是一个容纳了所有 OpenGL 内容与功能的对象，它储存了 OpenGL 实例相关的所有状态。创建上下文的方法在不同的平台都有所不同。在 Windows 平台上我们依靠 Win32 API 中的初始化函数创建上下文，这些函数一般都有 wgl 作为前缀。

在正式开始之前，我们首先需要创建一个窗口，并获取它的设备上下文。

```cpp
  HINSTANCE h_wgl_inst = GetModuleHandle(0);
  HWND h_wgl_wnd = MyCreateWnd(h_wgl_inst);
  HDC h_wgl_dc = GetDC(h_wgl_wnd);
```

函数 `HWND MyCreateWnd(HINSTANCE h_inst)` 是我自己定义的函数，窗口的具体创建过程请参考代码或是其他笔记。

首先我们需要了解一种名为 Pixel Format 的对象，它描述了帧缓冲器所具有的属性。一般用户无法直接创建 Pixel Format， 我们需要填写一个用于描述它的结构体，将这个结构体交给函数 `ChoosePixelFormat` ，以此来获取设备上下文所支持的最接近的 Pixel Format，然后设置它。

下面是一个示例，描述结构体的属性显然不会只有这么一点，更多的属性设置以及背后的意义可以参考[这里](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-pixelformatdescriptor)。

```cpp
  PIXELFORMATDESCRIPTOR des_pf = {
      .nSize = sizeof(des_pf),
      .nVersion = 1,
      .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      .iPixelType = PFD_TYPE_RGBA,
      .cColorBits = 32,
      .cAlphaBits = 8,
      .cDepthBits = 24,
      .cStencilBits = 8,
      .iLayerType = PFD_MAIN_PLANE,
  };

  int n_pf = ChoosePixelFormat(h_dc, &des_pf);
  if (!n_pf) {
    ErrorBox("Failed to find a suitable pixel format.");
  }
  if (!SetPixelFormat(h_dc, n_pf, &des_pf)) {
    ErrorBox("Failed to set the pixel format.");
  }
```

设置好 Pixel Format 后，创建上下文就很容易了。调用 `wglCreateContext`，它会返回一个上下文的句柄，将这个上下文设置为当前所使用的上下文后，就可以使用 OpenGL 了。

```cpp
  HGLRC h_rc = wglCreateContext(h_dc);
  if (!h_rc) {
    ErrorBox("Failed to create a OpenGL rendering context.");
  }
  if (!wglMakeCurrent(h_dc, h_rc)) {
    ErrorBox("Failed to activate the OpenGL rendering context.");
  }
```

OpenGL 的上下文是线程特定的，每一个线程都可以用以一个不同的上下文。需要注意的是，在多线程中使用相同的上下文是一件高风险的事情。

### 为 OpenGL 加载函数

在一般的 Demo 中， 这是像 GLAD 这样的库所完成的工作。OpenGL 不像其他的库只需要 include 进来就可以使用了。由于 OpenGL 本身实际上只是一套规范，具体的函数实现都是由平台和硬件方实现的，因此使用这些函数之前需要首先使用平台特定的 API 加载它们。

加载函数的流程是这样子的：

```cpp
typedef GLvoid(APIENTRY* PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
PFNGLBINDBUFFERPROC glBindBuffer =
    (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
```

然后就可以正常使用函数 `glBindBuffer` 了。

一般使用 OpenGL 的话，这一步骤还是交给第三方库来完成吧，手动载入函数并没有任何实质上的意义。在我的三角形 demo 中只是加载函数就占据了一半的代码量。

## 代码

[pure-ogl-triangle-demo](https://github.com/kopella/pure-ogl-triangle-demo/blob/master/Windows/win_main.c)
