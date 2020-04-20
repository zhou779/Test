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

	cout << "正在加载..." << endl;
	//预先加载
	for (int i = 1; i <= COUNT; i++) {

		sprintf(filename, "images2\\_%04d_图层-%d.jpg", 148 - i, i);
		loadimage(&images[i-1], filename);

	}

	initgraph(800, 450);

	mciSendString("play 极乐净土.mp3 repeat", 0, 0, 0);

	while (1) {
		//依次播放各个图片
		for (int i = 0; i < COUNT; i++) {
			//取图片(x,y,图片)
			putimage(0,0,&images[i]);
			Sleep(75);
		}
		

	}

	system("pause");

	closegraph();

	return 0;
}