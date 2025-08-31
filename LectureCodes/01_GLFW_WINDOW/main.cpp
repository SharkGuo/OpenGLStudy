#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>




//��Ӧ�����С�仯����
void frameBufferSizeCallBack(GLFWwindow*, int width, int height) {
	std::cout << "�����´�С��" << width << ", " << height << std::endl;
}

//������Ϣ�ص�����
void keyCallBack(GLFWwindow*, int key, int scancode, int action, int mods) {
	std::cout << "�����ˣ�" << key << std::endl;
}



int main() {

	//��ʼ��GLFW��������
	glfwInit();
	//����OpenGL���ΰ汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//����OpenGL���ú���ģʽ
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//�����������
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLStudy",  NULL, NULL);
	//���õ�ǰ�������ΪOpenGL�Ļ��ƶ���
	glfwMakeContextCurrent(window);
	//���������С�仯����Ϣ
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//����������Ϣ
	glfwSetKeyCallback(window, keyCallBack);



	//ִ�д���ѭ��
	while (!glfwWindowShouldClose(window)) {
		//���ܲ��ַ�������Ϣ
		//�����Ϣ�����Ƿ�����Ҫ�������Ϣ�������������������ն���
		glfwPollEvents();
	}



	//�Ƴ�����ǰ���������
	glfwTerminate();



	return 0;
}