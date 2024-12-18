# Lunify 🌙
A simple CLI to-do list application for Linux.

Quickly manage your tasks from the terminal!

![Help Page](./screenshots/help_page_screenshot_enhanced.png)
![List Tasks](./screenshots/list_tasks_screenshot_betterenhanced.png)

---

# Installation Instructions
Download the package from release\
Make it executable and move it to a valid path:
```bash
chmod +x lunify
sudo mv lunify /usr/bin
```
## Build locally
```bash
git clone https://github.com/rexept/lunify
cd lunify
mkdir build
cmake -DCMAKE_BUILD_TYPE=Release .. 
chmod +x lunify
sudo mv lunify /usr/bin
```
**Note**: You don't have to move it to /usr/bin, just a valid exported path.

# Build Instructions (for development)
Clone the package:
```bash
git clone https://github.com/rexept/lunify
```
Make build directory:
```bash
cd lunify
mkdir build
```
Initialize CMake
```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. 
```
