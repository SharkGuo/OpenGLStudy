 #include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>




//��Ӧ�����С�仯����
void frameBufferSizeCallBack(GLFWwindow*, int width, int height) {
	std::cout << "�����´�С��" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
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



	//ʹ��glad�������е�ǰ�汾opengl�ĺ���
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}



	//����opengl�ӿ��Լ�������ɫ
	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



	//ִ�д���ѭ��
	while (!glfwWindowShouldClose(window)) {
		//���ܲ��ַ�������Ϣ
		//�����Ϣ�����Ƿ�����Ҫ�������Ϣ�������������������ն���
		glfwPollEvents();

		//ִ��opengl����������
		glClear(GL_COLOR_BUFFER_BIT);

		//��Ⱦ����

		//�л�˫����
		glfwSwapBuffers(window);
	}



	//�Ƴ�����ǰ���������
	glfwTerminate();



	return 0;
}