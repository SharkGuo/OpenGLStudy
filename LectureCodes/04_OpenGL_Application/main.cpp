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

	//���������С�仯����Ϣ
	//glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//����������Ϣ
	//glfwSetKeyCallback(window, keyCallBack);







	//����opengl�ӿ��Լ�������ɫ
	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



	//ִ�д���ѭ��
	while (app->update()) {
		//ִ��opengl����������
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

		//��Ⱦ����

	}



	//�˳�����ǰ���������
	app->destory();



	return 0;
}