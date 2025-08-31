 #include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>




//响应窗体大小变化函数
void frameBufferSizeCallBack(GLFWwindow*, int width, int height) {
	std::cout << "窗体新大小：" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
}

//键盘消息回调函数
void keyCallBack(GLFWwindow*, int key, int scancode, int action, int mods) {
	std::cout << "按下了：" << key << std::endl;
}



int main() {

	//初始化GLFW基本环节
	glfwInit();
	//设置OpenGL主次版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//设置OpenGL启用核心模式
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//创建窗体对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLStudy",  NULL, NULL);
	//设置当前窗体对象为OpenGL的绘制对象
	glfwMakeContextCurrent(window);
	//监听窗体大小变化的消息
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//监听键盘消息
	glfwSetKeyCallback(window, keyCallBack);



	//使用glad加载所有当前版本opengl的函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}



	//设置opengl视口以及清理颜色
	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



	//执行窗体循环
	while (!glfwWindowShouldClose(window)) {
		//接受并分发窗体消息
		//检查消息队列是否又需要处理的消息，如果有则批量处理，清空队列
		glfwPollEvents();

		//执行opengl清理画布操作
		glClear(GL_COLOR_BUFFER_BIT);

		//渲染操作

		//切换双缓存
		glfwSwapBuffers(window);
	}



	//推出程序前做相关清理
	glfwTerminate();



	return 0;
}