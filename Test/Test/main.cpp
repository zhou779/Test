#include <iostream>
#include <Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define COUNT 148

using namespace std;
int main(void) {
	IMAGE images[COUNT];
	char filename[128];

	cout << "���ڼ���..." << endl;
	//Ԥ�ȼ���
	for (int i = 1; i <= COUNT; i++) {

		sprintf(filename, "images2\\_%04d_ͼ��-%d.jpg", 148 - i, i);
		loadimage(&images[i-1], filename);

	}

	initgraph(800, 450);

	mciSendString("play ���־���.mp3 repeat", 0, 0, 0);

	while (1) {
		//���β��Ÿ���ͼƬ
		for (int i = 0; i < COUNT; i++) {
			//ȡͼƬ(x,y,ͼƬ)
			putimage(0,0,&images[i]);
			Sleep(75);
		}
		

	}

	system("pause");

	closegraph();

	return 0;
}