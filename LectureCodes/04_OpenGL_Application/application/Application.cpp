#include "Application.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>


//初始化Application的静态变量
Application* Application::mInstance = nullptr;
Application* Application::getInstance(){
	if (mInstance == nullptr) {
		mInstance = new Application();
	}
	return mInstance;
}


Application::Application() {

}

Application::~Application() {

}



bool Application::init(const int& width, const int& height) {
	mWidth = width;
	mHeight = height;

	//初始化GLFW基本环节
	glfwInit();
	//设置OpenGL主次版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//设置OpenGL启用核心模式
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建窗体对象
	mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGLStudy", NULL, NULL);
	if (mWindow == NULL) {
		return false;
	}

	//设置当前窗体对象为OpenGL的绘制对象
	glfwMakeContextCurrent(mWindow);



	//使用glad加载所有当前版本opengl的函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}



	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);

	//键盘响应
	glfwSetKeyCallback(mWindow, keyCallback);



	return true;
}

bool Application::update() {
	if (glfwWindowShouldClose(mWindow)) {
		return false;
	}

	//接受并分发窗体消息
	//检查消息队列是否又需要处理的消息，如果有则批量处理，清空队列
	glfwPollEvents();

	//切换双缓存
	glfwSwapBuffers(mWindow);


	return true;
}

void Application::destory() {
	//退出程序前做相关清理
	glfwTerminate();
}

void Application::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	if (Application::getInstance()->mResizeCallback != nullptr) {
		Application::getInstance()->mResizeCallback(width, height);
	}
}

void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (Application::getInstance()->mKeyBoardCallback != nullptr) {
		Application::getInstance()->mKeyBoardCallback(key, action, mods);
	}
}