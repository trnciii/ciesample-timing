#include "robo_factory.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// ディスプレイリストの定義
#define ROBO_HEAD 1
#define ROBO_BODY 2

// ロボットの個数
#define MAX_ROBO 10

// 各ロボット胴体の位置
double body_pos_x[MAX_ROBO];

// 各ロボット頭の位置
double head_pos_x[MAX_ROBO];
double head_pos_y[MAX_ROBO];


// 登場する関数(いつもの)
void myinit(GLFWwindow** window);
void reshape(GLFWwindow* window, int w, int h);
void display(void);
// 入力を受け付ける関数
void KeyFunc(GLFWwindow* window, int key, int scancode, int action, int mods);
void MouseButtonFunc(GLFWwindow* window, int button, int action, int mods);
void MousePosFunc(GLFWwindow* window, double x, double y);
void MouseWheelFunc(GLFWwindow* window, double x, double y);

//--初期化—------------------------------------------------------------------
void myinit(GLFWwindow** window)
{
	glfwInit();
	glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
	
	int w = 600; // ウィンドウの幅
	int h = 600; // ウィンドウの高さ
	*window = glfwCreateWindow(w, h, "surface", NULL, NULL);
	glfwMakeContextCurrent(*window);
	glClearColor(0.5, 0.5, 1.0, 1.0);
	
	reshape(*window, w, h); // 視点の初期化をおこなう
	glEnable(GL_DEPTH_TEST);
 
	MakeListRoboHead( ROBO_HEAD );
	MakeListRoboBody( ROBO_BODY );

	//座標の初期化
	for(int i = 0; i < MAX_ROBO; i++){
		body_pos_x[i] = i*4+8;
		
		head_pos_x[i] = 0.0;
		head_pos_y[i] = 0.0;
	}
}


//--再描画--------------------------------------------------------------------
void reshape(GLFWwindow* window, int w, int h)
{
	glViewport( 0, 0, (GLsizei)w, (GLsizei)h ); //ウィンドウ全体をビューポートにする
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
   
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	gluLookAt(
		0.0, 0.0,30.0, //どこから見てるか
		0.0, 0.0, 0.0, //どこを見てるか
		0.0, 1.0, 0.0  //どの向きが上向きか
	);
}

//--キーボード関数--------------------------------------------------------------
void KeyFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// ↑
	if( key == GLFW_KEY_UP && action == GLFW_PRESS )
	{
		printf("↑\n");
	}
	
	// ↓
	if( key == GLFW_KEY_DOWN && action == GLFW_PRESS )
	{
		printf("↓\n");
	}
	
	// ←
	if( key == GLFW_KEY_LEFT && action == GLFW_PRESS )
	{
		printf("←\n");
	}
	
	// →
	if( key == GLFW_KEY_RIGHT && action == GLFW_PRESS )
	{
		printf("→\n");
	}
	
	// スペースキー
	if( key == GLFW_KEY_SPACE && action == GLFW_PRESS )
	{
		printf("SPACE\n");

		int w,h;
		glfwGetFramebufferSize(window, &w, &h);
		unsigned int* image = new unsigned int[w*h];
		
		glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, image);
		
		stbi_write_png("/適当な場所/capture.png", w, h, 3, image, 3*w);
		
		delete[] image;
	}
	
	// Aキー
	if( key == 'A' && action == GLFW_PRESS )
	{
		printf( "A\n" );
	}
}

//--マウスボタン関数------------------------------------------------------------
void MouseButtonFunc(GLFWwindow* window, int button, int action, int mods)
{
}

//--マウスの位置関数------------------------------------------------------------
void MousePosFunc(GLFWwindow* window, double x, double y)
{
}

//--マウスのホイール関数--------------------------------------------------------
void MouseWheelFunc(GLFWwindow* window, double x, double y)
{
}


//--描画内容--------------------------------------------------------------------
void display(int frame)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// 各胴体位置の更新と描画
	for(int i = 0; i < MAX_ROBO; i++){

		body_pos_x[i] += -0.2;

		// 体の描画
		glTranslated( body_pos_x[i], 0.0, 0.0 );
		glCallList( ROBO_BODY );
		glLoadIdentity();
		
		// 頭の描画
		glTranslated( head_pos_x[i], head_pos_y[i], 0.0 );
		glCallList( ROBO_HEAD );
		glLoadIdentity();
	}
}

//--メイン関数------------------------------------------------------------------
int main(void)
{
	//初期化処理 (ウィンドウサイズや表示位置、タイトル、背景色、...を決める)
	GLFWwindow* window; // ウィンドウの変数をつくる
	myinit(&window); // ウィンドウのポインタを渡して初期化
	

	//コールバック関数の登録 (キーボードやマウスの動きを捕まえる)
	glfwSetWindowSizeCallback(window, reshape);             // ウィンドウの大きさが変わると呼び出される
	glfwSetKeyCallback(window, KeyFunc);                    // キーボードを触ると呼び出される
	glfwSetMouseButtonCallback(window, MouseButtonFunc);    // マウスのボタンを押すと呼び出される
	glfwSetCursorPosCallback(window, MousePosFunc);         // マウスを動かすと呼び出される
	glfwSetScrollCallback(window, MouseWheelFunc);          // マウスホイールを動かすと呼び出される
	
	
	//イベント処理ループ
	int frame = 0;
	
	do{
		frame++;
		if(frame>300) frame = 0;
		
		display(frame);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}while( !glfwWindowShouldClose(window) );//ウィンドウが表示されるかぎりループする

   glfwTerminate();

	return 0;
}

