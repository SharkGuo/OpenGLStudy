 #include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"
#include "application/Application.h" 




void OnResize(int width, int height) {
	GL_CALL(glViewport(0, 0, width, height));
}

void OnKey(int key, int action, int mods) {
	std::cout << key << std::endl;
}




int main() {
	if(!app->init(800, 600)) {
		return -1;
	}

	app->setResizeCallback(OnResize);
	app->setKeyBoardCallback(OnKey);

	//监听窗体大小变化的消息
	//glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//监听键盘消息
	//glfwSetKeyCallback(window, keyCallBack);







	//设置opengl视口以及清理颜色
	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



	//执行窗体循环
	while (app->update()) {
		//执行opengl清理画布操作
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

		//渲染操作

	}



	//退出程序前做相关清理
	app->destory();



	return 0;
}