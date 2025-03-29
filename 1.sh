#!/bin/bash

# 设置颜色输出
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${GREEN}开始安装 DeepSeek-R1 模型...${NC}"

# 获取脚本所在目录的绝对路径
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# 安装Ollama（如果未安装）
echo "检查 Ollama 安装状态..."
if [ -d "/Applications/Ollama.app" ]; then
    echo "✅ Ollama 已安装，跳过安装步骤"
else
    echo "正在检查安装文件..."
    # 检查ollama目录是否存在
    if ! [ -d "${SCRIPT_DIR}/ollama" ]; then
        echo -e "${RED}❌ 错误：找不到ollama目录${NC}"
        echo "请在脚本同级目录下创建ollama文件夹：${SCRIPT_DIR}/ollama"
        exit 1
    fi
    
    # 检查Ollama.app是否在ollama目录中
    if ! [ -d "${SCRIPT_DIR}/ollama/Ollama.app" ]; then
        echo -e "${RED}❌ 错误：在ollama目录中找不到Ollama.app${NC}"
        echo "请将Ollama.app放置在：${SCRIPT_DIR}/ollama/Ollama.app"
        exit 1
    fi
    
    echo "正在部署 Ollama..."
    cp -R "${SCRIPT_DIR}/ollama/Ollama.app" /Applications/
    echo "✅ Ollama 已安装到 /Applications"
fi

# 检查模型文件是否存在
MODEL_PATH="${SCRIPT_DIR}/model/deepseek-r1-32b"
if ! [ -d "$MODEL_PATH" ]; then
    echo -e "${RED}错误: 未找到模型文件夹${NC}"
    echo "请确保模型文件夹存在于: ${MODEL_PATH}"
    exit 1
fi

# 创建 Ollama 模型目录
OLLAMA_MODELS_DIR="$HOME/.ollama/models"
mkdir -p "$OLLAMA_MODELS_DIR"

# 启动 Ollama（如果未运行）
open -a Ollama

# 等待 Ollama 服务启动
echo "等待 Ollama 服务启动..."
sleep 10

# 复制模型文件到 Ollama 目录
echo "正在导入模型文件..."
cp -R "$MODEL_PATH"/* "$OLLAMA_MODELS_DIR/"

# 使用 Modelfile 创建模型
echo "正在创建模型..."
ollama create deepseek-r1:32b -f "$MODEL_PATH/Modelfile"
ollama pull bge-m3

# 验证安装
echo "验证模型安装..."
if ollama list | grep -q "deepseek-r1"; then
    echo -e "${GREEN}DeepSeek-R1 模型安装成功！${NC}"
    echo "你现在可以使用以下命令来运行模型："
    echo "ollama run deepseek-r1"
else
    echo -e "${RED}模型安装可能出现问题，请检查日志${NC}"
fi 