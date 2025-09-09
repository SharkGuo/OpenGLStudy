#include "Application.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>


//��ʼ��Application�ľ�̬����
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

	//��ʼ��GLFW��������
	glfwInit();
	//����OpenGL���ΰ汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//����OpenGL���ú���ģʽ
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//�����������
	mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGLStudy", NULL, NULL);
	if (mWindow == NULL) {
		return false;
	}

	//���õ�ǰ�������ΪOpenGL�Ļ��ƶ���
	glfwMakeContextCurrent(mWindow);



	//ʹ��glad�������е�ǰ�汾opengl�ĺ���
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}



	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);

	//������Ӧ
	glfwSetKeyCallback(mWindow, keyCallback);



	return true;
}

bool Application::update() {
	if (glfwWindowShouldClose(mWindow)) {
		return false;
	}

	//���ܲ��ַ�������Ϣ
	//�����Ϣ�����Ƿ�����Ҫ�������Ϣ�������������������ն���
	glfwPollEvents();

	//�л�˫����
	glfwSwapBuffers(mWindow);


	return true;
}

void Application::destory() {
	//�˳�����ǰ���������
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