# 第1章概述

## 什么是OpenCV

OpenCV是一个开源的计算机视觉库，可以从[http://opencv.org](http://opencv.org)获取。
OpenCV库用C和C++语言编写，可以在Windows 、Linux 、Mac OS X等系统运行。同时也在积极开发Python 、Java 、Matlab 以及其他一些语言的接口，将库导入安卓和iOS 中为移动设备开发应用。
OpenCV设计用于进行高效的计算，十分强调实时应用的开发。它由C++语言编写并进行了深度优化，从而可以享受多线程处理的优势。

> 在英特尔架构上,可以购买英特尔的集成性能基元(IPP) 库，该库包含了许多算法领域的底层优化程序。在库安装完毕的情况下OpenCV在运行的时候会自动调用合适的IPP库。从OpenCV 3.0开始，英特尔许可OpenCV研发团队和OpenCV社区拥有一个免费的IPP库的子库（称IPPICV) , 该子库默认集成在OpenCV 中并在运算时发挥效用。

OpenCV 的一个目标是提供易千使用的计算机视觉接口，从而帮助人们快速建立精巧的视觉应用。OpenCV 库包含从计算机视觉各个领域衍生出来的500 多个函数，包括工业产品质怔检验、医学图像处理、安保领域、交互操作、相机校正、双目视觉以及机器人学。因为计算机视觉和机器学习经常在一起使用，所以OpenCV也包含一个完备的、具有通用性的机器学习库(ML模块）。

## OpenCV怎么用

OpenCV在世界范围内都非常流行，尤其是在中国、日本、俄罗斯、欧洲和以色列有着庞大的用户社区。
OpenCV的开源许可允许任何人利用OpenCV包含的任何组件构建商业产品。

## 什么是计算机视觉

> 计算机视觉这种技术可以将静止图像或视频数据转换为一种决策或新的表示。

在机器视觉系统中，计算机会从相机或者硬盘接收栅格状排列的数字,其不存在一个预先建立的模式识别机制，无法自动控制焦距和
光圈，也不能将多年的经验联系在一起，大部分的视觉系统都还处千一个作常朴素原始的阶段。

对于计算机而言，看到的只是按照栅格状排列的数字。所有在栅格中给出的数字还有大量的噪声，所以每个数字只能给我们提供少量的信息，我们的任务变成将这个带有噪声的数字栅格转换为感知结果。

给定一个对于3D世界的二维(2D) 观测，就不存在一个唯一的方式来重建三维信号。即使数据是完美的，相同的二维图像也可能表示一个无限的3D场景组合中的任一种情况。数据会被噪声和畸变所污染。这样的污染源于现实生活中的很多方面（天气、光线、折射率和运动），还有传感器中的电路噪声以及其他的一些电路系统影响，还有在采集之后对于图像压缩产生的影响。

在经典的系统设计中，额外场景信息可以帮助我们从传感器的层面改善获取信息的质量。对于噪声，一般使用统计的方法来对抗。

OpenCV 的目标是为计算机视觉需要解决的问题提供工具。在某些情况下，函数库中的高级功能可以有效解决计算机视觉中的问题。

## OpenCV的起源

OpenCV缘起于英特尔想要增强CPU集群性能的研究。该项目的结果是英特尔启动了许多项目，包括实时光线追踪算法以及三维墙体的显示。

以下是OpenCV想要完成的一些目标：

- 为高级的视觉研究提供开源并且优化过的基础代码，不再需要重复造轮子。
- 以提供开发者可以在此基础上进行开发的通用接口为手段传播视觉相关知识，这样代码有更强的可读性和移植性。
- 以创造可移植的、优化过的免费开源代码来推动基千高级视觉的商业应用，这些代码可以自由使用，不要求商业应用程序开放或免费。

OpenCV得到了来自很多用户的贡献，研发主力也很大部分转移到英特尔之外。

在成为一个开源的函数库之后， OpenCV经过柳树车库（Willow Garage）几年的开发，现在已经得到了OpenCV基金会的支持。在今天， OpenCV 由基金会以及一些上市公司和私人机构开发。

### OpenCV的结构

OpenCV是由层级结构组织的。处于最上层的是OpenCV和操作系统的交互。接下来是语言绑定和示例应用程序。再下一层opencv_contrib模块所包含的OpenCV 由其他开发人员所贡献的代码，其包含大多数高层级的函数功能。这就是OpenCV的核心。底层是基于硬件加速层(HAL) 的各种硬件优化。

[OpenCV 3](img_OpenCV/Learning OpenCV 3.jpg)

### 使用IPP来加速OpenCV

如果在英特尔的处理器上使用， OpenCV就会自动使用一种免费的英特尔集成性能原语库(IPP) 的子集， IPP 8.x(IPPICV) 。IPPICV可以在编译阶段链接到OpenCV, 这样一来，会替代相应的低级优化的C语言代码（在cmake 中设置 `WITH_IPP=ON/OFF` 开启或者关闭这一功能，默认情况为开启）。

### 谁拥有OpenCV

尽管Gary Bradski在英特尔发起了OpenCV项目，但这个函数库的宗旨是促进商业和研究，这正是它的使命。因此，它是开源并且免费的，并且无论是研究还是商业目的代码都可以（全部或者部分的）使用或者被嵌入到其他程序中。它并不强制你声明基于此开发的代码必须是免费或者开源的。

## 下载和安装OpenCV

> OpenCV 官方网站
>
> [http://opencv.org/](http://opencv.org/)
>
> 下载最新的且完整的源码以及大部分的release版本源码。

> 下载页面
>
> [http://opencv.org/downloads.html](http://opencv.org/downloads.html)

> 最新的代码
>
> [https://github.com/opencv/opencv](https://github.com/opencv/opencv)

> 下载和编译opencv_contrib模块
>
> [https://github.com/opencv/opencv_contrib](https://github.com/opencv/opencv_contrib)

### 安装

OpenCV使用Git作为版本管理工具，使用Cmake来构建工程。

#### Windows 系统

在[http://opencv.org/downloads.html](http://opencv.org/downloads.html), 可以发现最新的为Windows准备的最新版本OpenCV下载链接。可以通过这个链接下载一个EXE文件，该文件会把预编译好的OpenCV解压到你的电脑上，预编译版本支持不同版本的Visual Studio环境。

需要再添加一个名为 `OPENCV_DIR`的环境变晕来告诉编译器在哪里找到OpenCV的二进制文件。可以通过命令行工具对此进行设置。

```cmd
setx -m OPENCV_DIR D:\OpenCV\Build\x64\vc10
```

如果希望静态链接OpenCV, 就只需要做到这一步。如果希望使用OpenCV 的动态链接库(DLL) , 就需要告诉系统在哪里找到它的二进制库。只需要在库路径中添加 `%0PENCV_DIR%\bin`。

OpenCV3 集成了IPP, 所以如果使用最新的x86或者x64CPU, 就可以获得或多或少的性能优势。

按照如下操作从源码编译OpenCV ：

* 运行CMake GUI。
* 指定OpenCV源码所在路径以及构建目标文件夹（必须和源码所在路径不同）。
* 按两次Configure键（选择可以使用的Visual Studio编译器或者MinGW构建文件，如果正在使用MinGW的话），直到所有条目没有红色警示。
* 使用Visual Studio打开生成的解决方案并构建。如果使用的是MinGW, 则按照Linux的安装指导进行。

> 注意：尽管Windows环境拥有预编译的release版本的库、但是它并不包含debug版本的库。所以，在开发OpenCV之前，需要打开解决方案并且自行编译那些库。

#### Linux 系统

略

#### Mac系统

略

## 从Git获取最新的OpenCV

> 寄存于 Github 上
>
> [https://github.com/opencv/opencv.git](https://github.com/opencv/opencv.git)

## 更多的OpenCV文档

> OpenCV 基础文档
>
> [https://opencv.org](https://opencv.org)

> 深入教程
>
> [https://docs.opencv.org/3.4.15/d9/df8/tutorial_root.html](https://docs.opencv.org/3.4.15/d9/df8/tutorial_root.html)

> 维基网站
>
> [https://github.com/opencv/opencv/wiki](https://github.com/opencv/opencv/wiki)

### 提供的文档

OpenCV 2.x 提供PDF格式的完整的引用手册以及丰富的教程，查看openev/doc 目录就可以得到。从OpenCV 3.x开始，就不再提供离线的文档了。

### 在线文档和维基资源

在[https://opencv.org](https://opencv.org)上有大量的文档和维基资源。

> 参考
> 这个部分包含函数、它们的参数以及如何使用它们的一些信息。
> [https://docs.opencv.org](https://docs.opencv.org)
> 参考划分为几个部分，每个部分都和库中一个模块有关。具体的模块列表随着时间推移而不断的发展，但模块始终是组成这个库的基本单位。每个函数都是一个模块的一部分，以下是当前OpenCV所拥有的模块:

> `Core`
>
> - 该模块包含OpenCV库的基础结构以及基本橾作。
>
> `Improc`
>
> - 图像处理模块包含基本的图像转换，包括滤波以及类似的卷积操作。
>
> `Highgui`
>
> - 在OpenCV 3.0 中， 分割为i mcodecs 、videoio以及highgui 三部分。
> - 这个模块包含可以用来显示图像或者简单的输入的用户交互函数。这可以看作是一个非常轻量级的Windows UI工具包。
>
> `Video`
>
> - 该模块包含读取和写视频流的函数。
>
> `Calib3d`
>
> - 这个模块包括校准单个、双目以及多个相机的算法实现。
>
> `Feature2d`
>
> - 这个模块包含用千检测、描述以及匹配特征点的算法。
>
> `Objdectect`
>
> - 这个模块包含检测特定目标，比如人脸或者行人的算法。也可以训练检测器并用来检测其他物体。
>
> `Ml`
>
> - 机器学习模块本身是一个非常完备的模块，包含大量的机器学习算法实现并且这些算法都能和OpenCV 的数据类型自然交互。
>
> `Flann`
>
> - Flann的意思是“快速最邻近库” 。这个库包含一些你也许不会直接使用的方法，但是其他模块中的函数会调用它在数据集中进行最邻近搜索。
>
> `GPU`
>
> - 在OpenCV 3.x 中被分割为多个cuda* 模块
> - GPU模块主要是函数在CUDA GPU上的优化实现，此外，还有一些仅用于GPU的功能。其中一些函数能够返回很好的结果，但是需要足够好的计算资源，如果硬件没有GPU, 则不会有什么提升。
>
> `Photo`
>
> - 这是一个相当新的模块，包含计算摄影学的一些函数工具。
>
> `Stitching`
>
> - 本模块是一个精巧的图像拼接流程实现。这是库中的新功能，但是，就像Photo模块一样，这个领域未来预计有很大的增长。
>
> `Nonfree`
>
> - 在OpenCV 3.0 中，被移到opencv_contriblxfeatures2d
> - OpenCV 包含一些受到专利保护的或者受到使用限制的（比如SIFT算法）算法。这些篡法被隔离到它们自己的模块中，以表明你需要做一些特殊的工作，才可以在商业产品中使用它们。
>
> `Contrib`
>
> - 在OpenCV 3.0 中，融合进了opencv_contrib。
> - 这个模块包含一些新的、还没有被集成进OpenCV库的东西。
>
> `Legacy`
>
> - 在OpenCV 3.0 中，被取消
> - 这个模块包含一些老的尚未被完全取消的东西。
>
> `Ocl`
>
> - 在OpenCV 3.0中，被取消，取而代之的是T-API。
> - 一个较新的模块，可以认为它和GPU 模块相似，它实现了开放并行编程的Khronos OpenCL标准。虽然现在模块的特性比GPU模块少很多，但Ocl模块的目标是提供可以运行在任何GPU或者是其他可以搭载Khronos 的并行设备。这与GPU模块形成了鲜明的对比，后者使用Nividia CUDA工具包进行开发，因此只能在Nividia GPU设备上工作。

> 教程
>
> 这个部分是许多教程的集合，这些教程会告诉你如何完成各种各样的事情。这里有一些基础课程的教程（比如如何在不同平台上安装OpenCV或者创建OpenCV 项目）以及一些更高级的话题（比如目标检测的背景提取算法）。
> [https://docs.opencv.org/master/d9/df8/tutorial_root.html](https://docs.opencv.org/master/d9/df8/tutorial_root.html)

> 速查表
>
> 只有一页篇幅的PDF文档，包含整个库的高度压缩的参考。
> [http://docs.opencv.org/3.0-last-rst/opencv_cheatsheet.pdf](http://docs.opencv.org/3.0-last-rst/opencv_cheatsheet.pdf)

> 维基
>
> 维基包含所有你可能想要的东西，甚至可能超乎你的想象。在这里，可以找到路线图、新闻、开放问题、bug追踪以及无数个更深入的主题，比如如何成为OpenCV 的贡献者。
> [https://github.com/opencv/opencv/wiki](https://github.com/opencv/opencv/wiki)

> 问答社区
>
> 问答社区是一个庞大的、包含数千个人遇到过的问题的档案集合。可以在这里向OpenCV社区提问，或者通过回答问题帮助其他人。
> [https://forum.opencv.org/](https://forum.opencv.org/)

## OpenCV贡献库

在OpenCV 3.0 中，先前单一的库分成两部分：成熟的OpenCV和opencv_contrib 中的最新模块。前者巾核心的OpenCV 团队维护，并且包含（大部分）稳定的代码，而后者则不成熟，主要由社区维护和开发，可能有非OpenCV许可的部分，并且可能包括受专利保护的算法。

以下是一些可以在opencv_contrib 中获得的模块：

- `Dnn`
  深度神经网络。
- `Face`
  人脸识别。
- `Text`
  文本检测以及识别，基千许多开源的OCR算法。
- `Rgbd`
  处理由Kinect或者其他深度传感器（或者简单的由双目匹配得到的）获取的RGB+深度图像。
- `Bioinspired`
  一些基于生物学启发的视觉技术。
- `ximgproc和xphoto`
  先进的图像处理以及计算摄影学方法。
- `Tracking`
  现代目标追踪算法。

### 下载和编译Contributed模块

使用git 下载opencv_contrib模块

```cmd
git clone https://github.com/opencv/opencv_contrib.git
```

使用Cmake编译

```cmd
cmake -D CMAKE_BUILD_TYPE=Release -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules ..
```

编译好的Contributed会和普通的OpenCV模块处于同样的目录，不需要任何特殊的配置就可以使用它们。

## 可移植性

OpenCV基千可移植的理念设计，最初可以被任意通用的C++编译器编译。这表示它的C和C++代码都必须是相当标准的，以便跨平台支持更加容易。

在运行平台的支持方面，OpenCV对于Intel和AMD 32位，64位(x86, x64) 的支持是最成熟的，对ARM的支持也在迅速改善中。

在操作系统方面，OpenCV完全支持Windows、Linux、OS X、Android和iOS。

事实上， OpenCV 已经被移植到几乎所有商用系统中，从亚马逊云以及40核的英特尔Xeon Phi到树苺派和机器狗中。


|                  | x86/x64                         | ARM                       | 其他：MIP、PPC |
| ------------------ | --------------------------------- | --------------------------- | ---------------- |
| Windows          | SIMD， IPP， Parallel，I/O      | SIMD， Parallel(3.0)，I/O | N/A            |
| Linux            | SIMD， IPP， Parallel，I/O      | SIMD， Parallel，I/O      | Parallel，I/O  |
| Android          | SIMD， IPP(3.0)， Parallel，I/O | SIMD， Parallel，I/O      | MIPS 基本支持  |
| OS X/IOS         | SIMD， IPP(3.0)， Parallel，I/O | SIMD， Parallel，I/O      | N/A            |
| 其他：BSD、QNX等 | SIMD                            | SIMD                      |                |

Linux 中的并行化是通过笫三方库或启用OpenMP 来实现的
Android设各中并行是通过TBB进行的

- SIMD
  用于加速的向量指令：基于x86, x64, NEON以及ARM的SSE指令集。
- IPP
  可否使用英特尔IPP 加速，从3.0 版本开始，函数库自带一个IPP 的免费子库(IPPICV) 。
- Parallel
  一些用于在多核进行线程控制的标准或者第三方线程框架。
- I/O
  一些用于抓取或者写视频的标准或第三方API。

# 第2章 OpenCV初探

## 头文件

OpenCV的头文件是按照第1章的模块组织的。
`.../include/opencv2/opencv.hpp` 包含了OpenCV各个模块的头文件：

- `#include "opencv2/core/core_c.h"`

  旧式C风格的结构以及运算
- `#include "opencv2/core/core.hpp"`

  新式C++风格的结构以及数学运算
- `#include "opencv2/flann/miniflann.hpp"`

  最邻近搜索匹配函数
- `#include "opencv2/imgproc/imgproc_c.h"`

  旧式C风格的图像处理函数
- `#include "opencv2/imgproc/imgproc.hpp"`

  新式C++风格图像处理函数
- `#include "opencv2/video/photo.hpp"`

  操作和恢复照片相关算法
- `#include "opencv2/video/video.hpp"`

  视觉追踪以及背景分割
- `#include "opencv2/features2d/features2d.hpp"`

  用于追踪的二维特征
- `#include "opencv2/objdetect/objdetect.hpp"`

  级联人脸分类器、latent SVM分类器、HoG特征和平面片检测器
- `#include "opencv2/calib3d/calib3d.hpp"`

  校准以及双目视觉相关
- `#include "opencv2/ml/ml.hpp"`

  机器学习、聚类以及模式识别相关
- `#include "opencv2/highgui/highgui_c.h"`

  旧式C风格的显示、滑动条、鼠标操作以及输入输出相关
- `#include "opencv2/highgui/highgui.hpp"`

  新式C++风格的显示、滑动条、鼠标操作以及输入输出相关
- `#include "opencv2/contrib/contrib.hpp"`

  用户贡献的代码、皮肤检测、模糊Mean-Shift追踪、spin image算法及自相似特征等

可以使用头文件opencv.hpp来包含所有可能在OpenCV 函数中用到的头文件，但是这会减慢编译的速度。如果只使用特定的库，只包含特定的头文件所消耗的编译时间会比包含opencv.hpp消耗的编译时间少很多。这些头文件在 `.../modules`文件夹中。比如， `imgproc.hpp`存在于 `...lmodules/imgproc/include/opencv2/imgproclin1gproc.hpp` 。类似，函数对应的源文件也存在于对应的src 文件夹中。比如， `improc`模块的 `cv::Canny()`函数存在于 `.../modules/improc/src/canny.cpp`。

> 可以使用 `opencv2/legacy/legacy.hpp`来调用遗留代码，比如说比较旧的斑点追踪、隐马尔科夫模型( HMM ) 检测、聚合追踪以及特征目标。其他位于 `.../modules/legacy/include/opencv2/legacy/legacy.hpp` 。

### 资源

几个不错的OpenCV 资源：

- 对整个OpenCV库进行概述：

  [https://www.slideshare.net/zblair/opencv-introduction](https://www.slideshare.net/zblair/opencv-introduction)
- OpenCV3 概述

  [https://slideplayer.com/slide/10302485/](https://slideplayer.com/slide/10302485/)
- 关于加速的讨论

  [https://www.slideshare.net/embeddedvision/making-opencv-code-run-fast-a-presentation-from-intel](https://www.slideshare.net/embeddedvision/making-opencv-code-run-fast-a-presentation-from-intel)
- 关于模块的讨论

  [https://docs.opencv.org/3.1.0/](https://docs.opencv.org/3.1.0/)

## 第一个程序

OpenCV提供了一些实用工具来读取从视频流到摄像机画面的各种各样的图像格式，这些工具都是HighGUI的一部分。

打开一张图像并且将其显示在屏幕上的代码。


```c++
int x;
```
