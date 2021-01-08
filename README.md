この資料は、従来版の後半第3回 -	タイミングアクションの制作 に対応します。

ロボット工場でロボットの頭を取り付けるという簡単なゲームを作成します。 ここではタイミング要素をインタラクションに取り入れ、↓キーを押すとロボットの頭が落ちるようにします。 頭が体の上に乗るとロボット製作成功というルールにします。

![](docs/tiser.gif)

## 目次
* [準備](#準備)
	* [プログラム解説](#プログラム解説)
* [頭の投下](#頭の投下)
* [頭と胴体の交差判定](#頭と胴体の交差判定)
* [](#)
* [](#)
* [](#)
* [](#)


## 準備

ダウンロードした状態のプログラムは、右から胴体が10個流れてくるというものです。
今回は以下の順でプログラムを完成させていきます。

1. キーボード操作による頭の投下
2. 胴体との交差判定と動きのコントロール


### プログラム解説

今回使うロボットはすでに[ディスプレイリスト](https://github.com/trnciii/cge2020mac/tree/2_surface#ディスプレイリスト)として定義してあり、`glCallList( ROBO_BODY )`, `glCallList( ROBO_HEAD )`とすることでそれぞれロボットの体と頭をよびだすことができます。

動きをコントロールするための変数として以下がグローバルに定義されています。

```cpp
// 各ロボットの体のx座標
double body_pos_x[MAX_ROBO];

// 各ロボットの頭の座標
double head_pos_x[MAX_ROBO];
double head_pos_y[MAX_ROBO];
```

また`myinit`では各座標の初期化を、`display`関数では胴体の位置更新と描画をおこなっています。

[ void myinit(GLFWwindow** window) ]

```cpp
// ...

	//座標の初期化
	for(int i = 0; i < MAX_ROBO; i++){
		body_pos_x[i] = i*4+8;
		
		head_pos_x[i] = 0.0;
		head_pos_y[i] = 0.0;
		used[i] = false;
		complete[i] = false;
	}

// ...

```

[ void display(int frame) ]

```cpp
// ...

	// 各ロボット位置の更新
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

// ...
```

以上が配布プログラムの要点です。

## 頭の投下

適当なキーを押したら頭が落下するようにします。以下、"↓"を押すことに決めて説明をします。

### 考えかた
それぞれの頭部はキーを押すごとに一つづつ落下していきます。
いま何個の頭まで落下しているか数えておき、その範囲だけ動かすようにします。

### 実装
グローバル変数として以下のように`used = 0`を追加してください。

```cpp
// -- ロボットの座標などの宣言 --

// 追加. 何個めの頭まで落下したか
int used = 0;
```

`used`はキーを押すごとに増加します。ただし、用意した配列外の数にならないようにします。

```cpp
void KeyFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// ↓
	if( key == GLFW_KEY_DOWN && action == GLFW_PRESS )
	{
		printf("↓\n");
		if(used<MAX_ROBO) used++; // 追記
	}
}
```

最後に、配列の **[0, used)** の範囲で頭を落下させます。
`display`の中で頭の座標を更新します。

```cpp
void display(int frame){
	// ...

	// 追記分. 各頭部の更新
	for(int i=0; i<used; i++){
		head_pos_y[i] -= 0.8;
	}
	
	// 各胴体位置の更新と描画
	for(int i = 0; i < MAX_ROBO; i++){

		body_pos_x[i] += -0.2;
		// ...
```

以上で、全部で10個ある頭が一個ずつ落下していくという処理ができました。

















