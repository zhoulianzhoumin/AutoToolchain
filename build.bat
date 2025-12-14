@echo off
:: 设置正确的字符编码
chcp 65001 >nul

:: 设置构建类型
set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

:: 显示当前目录，方便调试
echo 当前工作目录：%cd%
echo.

:: 设置路径
set SOURCE_FOLDER=projects_2025
set BUILD_FOLDER=build_%BUILD_SUFFIX%

:: 检查源目录是否存在
if not exist "%SOURCE_FOLDER%" (
    echo 错误：找不到源目录 "%SOURCE_FOLDER%"
    echo 当前目录下的文件夹：
    dir /ad /b
    pause
    exit /b 1
)

:: 显示路径信息
echo 源目录：%SOURCE_FOLDER%
echo 构建目录：%BUILD_FOLDER%
echo.

:: 创建构建目录
if not exist "%BUILD_FOLDER%" (
    echo 创建构建目录：%BUILD_FOLDER%
    mkdir "%BUILD_FOLDER%"
)

:: 进入构建目录并运行CMake
echo 运行CMake配置...
cd "%BUILD_FOLDER%"
cmake -G "%BUILD_TYPE%" "..\%SOURCE_FOLDER%"

:: 检查CMake是否成功
if %errorlevel% equ 0 (
    echo CMake配置成功！
    echo.
    
    echo 开始编译...
    cmake --build .
    
    :: 复制文件
    echo 复制文件...
    if exist "..\%SOURCE_FOLDER%\MergeSort\merge_sort.bat" (
        copy "..\%SOURCE_FOLDER%\MergeSort\merge_sort.bat" ".\MergeSort\"
        echo 文件复制成功！
    ) else (
        echo 警告：找不到要复制的文件
    )
) else (
    echo CMake配置失败！
)

:: 暂停查看结果
echo.
pause