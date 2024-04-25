# 当前文件夹路径
SRC_DIR := $(CURDIR)
# 编译文件夹
BUILD_DIR := $(SRC_DIR)/build

# 编译器和链接器
CXX := g++
LD := g++

# 编译器标志
CXXFLAGS := -g -O0 -Wall -static -std=c++20

# 链接器标志，包括库的搜索路径和链接的库
LDFLAGS := -lz3

# 自动获取源文件列表和目标文件列表
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET := test

# 默认目标
all: $(TARGET)

# 如何生成最终的可执行文件
$(TARGET): $(OBJECTS)
	$(LD) $(OBJECTS) -o $@ $(LDFLAGS)

# 如何从.cpp文件生成.o文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建 build 目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 清除生成的文件
clean:
	rm -rf $(BUILD_DIR)