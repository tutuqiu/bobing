# 博饼控制台小游戏

## 项目简介
本项目是一个基于 Windows 控制台的“博饼”小游戏，使用 C++ 编写，支持骰子动画和玩法判定，适合学习和娱乐。

## 游戏玩法
- 运行程序后，按回车键开始掷骰子。
- 每轮会自动掷出 6 个骰子，并根据结果判定奖项。
- 按回车进入下一轮，按空格可直接结束游戏并显示最高纪录。

## 主要功能
- 控制台彩色输出与光标控制
- 骰子图案绘制与动画
- 自动判定“博饼”各类奖项

## 依赖环境
- Windows 操作系统
- Visual Studio 或支持 Windows API 的 C++ 编译器

## 编译方法
1. 使用 Visual Studio 新建空项目，将 `mydemo.cpp`、`cmd_console_tools.cpp`、`cmd_console_tools.h` 添加到项目中。
2. 编译生成可执行文件。

或使用命令行：
```powershell
g++ mydemo.cpp cmd_console_tools.cpp -o bobing.exe -std=c++11 -static -lgdi32
```
（需安装 MinGW 并配置好环境变量）

## 运行方法
在 `Debug` 或编译输出目录下，双击 `bobing.exe` 或在命令行输入：
```powershell
./bobing.exe
```

## 文件说明
- `mydemo.cpp`：主程序，包含游戏逻辑和界面
- `cmd_console_tools.cpp/h`：控制台操作工具库
- `Debug/`：编译输出目录


