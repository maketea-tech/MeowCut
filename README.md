# MeowCut

## build
根目录、`app`目录和`core`目录下均包含`CMakeLists.txt`文件，但`app`目录和`core`目录下的不建议使用（也不能使用），建议编译方式（在根目录下）为：
1. `mkdir build && cd build`
2. 根据需要使用下面的`cmake`参数
```
cmake 
    -D Qt_Path=<qt5 sdk路径，需要包含Qt5Config.cmake文件，如果环境变量设置了QT_DIR或Qt5_DIR，此项可以省略> 
    -D CMAKE_BUILD_TYPE=<debug或release, 默认debug，这两个选项添加了不同的编译选项> 
    -D SOFTWARE_TYPE=<app、lib、demo, 默认app> 
    -D SOFTWARE_VERSION=<版本号，默认0.1> 
    -D CXX_STANDARD=<11,14,17，C++标准，默认17，此选项没有做检查> 
    -D INSTALL_PREFIX=<目标文件路径，默认build目录下的bin目录>
    -D DEMO_TYPE=<audio_effect、avcodec、avsync、image_filter、meowcut_core、video_render中的一个，demo模式下生效>
    ..
```
3. `make -j4`
4. 编译后生成的文件位于`INSTALL_PREFIX/bin/系统名`文件夹中