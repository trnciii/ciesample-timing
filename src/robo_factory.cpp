#include "robo_factory.h"

/* 
 * --ボックスの描画関数----------------------------------------------------------------------
 * 
 * 	原点中心に幅width, 高さheight, 奥行きlengthのボックスを描画
 *  一番最後は描画のタイプを指定。何も指定しない場合、自動で「GL_LINE_LOOP」
 * -----------------------------------------------------------------------------------------
 */
void makebox(double width, double height, double length, GLenum type)
{
	double box[8][3];	//頂点データ格納用配列

	//頂点データの格納
	box[0][0] = -width/2;	box[0][1] =  height/2;	box[0][2] = length/2;	
	box[1][0] = -width/2;	box[1][1] = -height/2;	box[1][2] = length/2;
	box[2][0] =  width/2;	box[2][1] = -height/2;	box[2][2] = length/2;
	box[3][0] =  width/2;	box[3][1] =  height/2;	box[3][2] = length/2;
	
	box[4][0] = -width/2;	box[4][1] =  height/2;	box[4][2] = -length/2;
	box[5][0] = -width/2;	box[5][1] = -height/2;	box[5][2] = -length/2;
	box[6][0] =  width/2;	box[6][1] = -height/2;	box[6][2] = -length/2;
	box[7][0] =  width/2;	box[7][1] =  height/2;	box[7][2] = -length/2;

	//前面描画・黄色
	glColor3d(1.0, 1.0, 0.0);
	glNormal3d(0.0, 0.0, 1.0);
	glBegin(type);
		glVertex3dv(box[0]);
		glVertex3dv(box[1]);
		glVertex3dv(box[2]);
		glVertex3dv(box[3]);
	glEnd();

	//後面描画・赤
	glColor3d(1.0, 0.0, 0.0);
	glNormal3d(0.0, 0.0, -1.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[5]);
		glVertex3dv(box[6]);
		glVertex3dv(box[7]);
	glEnd();
	
	//上面描画・マゼンダ
	glColor3d(1.0, 0.0, 1.0);
	glNormal3d(0.0, 1.0, 0.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[0]);
		glVertex3dv(box[3]);
		glVertex3dv(box[7]);
	glEnd();

	//右面描画・緑
	glColor3d(0.0, 1.0, 0.0);
	glNormal3d(1.0, 0.0, 0.0);
	glBegin(type);
		glVertex3dv(box[3]);
		glVertex3dv(box[2]);
		glVertex3dv(box[6]);
		glVertex3dv(box[7]);
	glEnd();

	//左面描画・シアン
	glColor3d(0.0, 1.0, 1.0);
	glNormal3d(-1.0, 0.0, 0.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[5]);
		glVertex3dv(box[1]);
		glVertex3dv(box[0]);
	glEnd();
	
	//下面描画・青
	glColor3d(0.0, 0.0, 1.0);
	glNormal3d(0.0, -1.0, 0.0);
	glBegin(type);
		glVertex3dv(box[6]);
		glVertex3dv(box[5]);
		glVertex3dv(box[1]);
		glVertex3dv(box[2]);
	glEnd();
}

/* 
 * --Robot用ボックスの描画関数----------------------------------------------------------------------
 * 
 * 　ロボット用のmakebox関数。単色の箱を描画
 * -----------------------------------------------------------------------------------------
 */
void makeboxROBOT(double width, double height, double length, GLenum type)
{
	double box[8][3];	//頂点データ格納用配列

	//頂点データの格納
	box[0][0] = -width/2;	box[0][1] =  height/2;	box[0][2] = length/2;	
	box[1][0] = -width/2;	box[1][1] = -height/2;	box[1][2] = length/2;
	box[2][0] =  width/2;	box[2][1] = -height/2;	box[2][2] = length/2;
	box[3][0] =  width/2;	box[3][1] =  height/2;	box[3][2] = length/2;
	
	box[4][0] = -width/2;	box[4][1] =  height/2;	box[4][2] = -length/2;
	box[5][0] = -width/2;	box[5][1] = -height/2;	box[5][2] = -length/2;
	box[6][0] =  width/2;	box[6][1] = -height/2;	box[6][2] = -length/2;
	box[7][0] =  width/2;	box[7][1] =  height/2;	box[7][2] = -length/2;

	//前面描画
	glNormal3d(0.0, 0.0, 1.0);
	glBegin(type);
		glVertex3dv(box[0]);
		glVertex3dv(box[1]);
		glVertex3dv(box[2]);
		glVertex3dv(box[3]);
	glEnd();

	//後面描画
	glNormal3d(0.0, 0.0, -1.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[5]);
		glVertex3dv(box[6]);
		glVertex3dv(box[7]);
	glEnd();
	
	//上面描画
	glNormal3d(0.0, 1.0, 0.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[0]);
		glVertex3dv(box[3]);
		glVertex3dv(box[7]);
	glEnd();

	//右面描画
	glNormal3d(1.0, 0.0, 0.0);
	glBegin(type);
		glVertex3dv(box[3]);
		glVertex3dv(box[2]);
		glVertex3dv(box[6]);
		glVertex3dv(box[7]);
	glEnd();

	//左面描画
	glNormal3d(-1.0, 0.0, 0.0);
	glBegin(type);
		glVertex3dv(box[4]);
		glVertex3dv(box[5]);
		glVertex3dv(box[1]);
		glVertex3dv(box[0]);
	glEnd();
	
	//下面描画
	glNormal3d(0.0, -1.0, 0.0);
	glBegin(type);
		glVertex3dv(box[6]);
		glVertex3dv(box[5]);
		glVertex3dv(box[1]);
		glVertex3dv(box[2]);
	glEnd();
}

void MakeListRoboHead( int list )
{
	// ディスプレイリスト1
	// 頭
	glNewList(list, GL_COMPILE);
	glPushMatrix();

		glTranslated( 0, 4, 0);
		glColor3d(0.8, 0.8, 0.0);
		makeboxROBOT( 0.4, 1.2, 0.4, GL_POLYGON );//首パーツ	

		glTranslated(0.0, 0.6, 0.0);
		glColor3d(1.0, 1.0, 0.0);
		makeboxROBOT( 1.0, 1.0, 1.0, GL_POLYGON  );//頭パーツ	
		
		
		glTranslated(0.0, 0.0, 0.3);
		glColor3d(0.0, 0.8, 0.0);
		makeboxROBOT( 1.2, 0.3, 0.6, GL_POLYGON  );//頭パーツ	

	glPopMatrix();
	glEndList();
}

void MakeListRoboBody( int list )
{
	// ディスプレイリスト2
	// ロボットの描画
	glNewList(list, GL_COMPILE);
	glPushMatrix();
		
		glTranslated( 0, -4, 0);
		glColor3d(0.0, 1.0, 1.0);
		makeboxROBOT( 1.3, 0.7, 1.0, GL_POLYGON  );//腰パーツ
		
		glPushMatrix();
			glTranslated(0.0, -0.3, 0.0);
			glColor3d(0.0, 0.8, 0.8);
			makeboxROBOT( 0.5, 1.0, 0.9, GL_POLYGON  );

			glTranslated(0.0, -0.3, 0.0);
			glColor3d(1.0, 0.0, 1.0);
			makeboxROBOT( 2.0, 0.2, 0.2, GL_POLYGON  );
		glPopMatrix();

		// 胴体
		glPushMatrix();
		glTranslated(0.0, 0.4, 0.0);

		glTranslated(0.0, 0.3, 0.0);
		glColor3d(0.8, 0.0, 0.0);
		makeboxROBOT( 0.6, 1.0, 0.6, GL_POLYGON  );//腹パーツ

		glTranslated(0.0, 0.6, 0.0);
		glColor3d(1.0, 0.0, 0.0);
		makeboxROBOT( 1.8, 1.2, 1.0, GL_POLYGON  );//胸パーツ
			
		glTranslated(0.0, 0.3, 0.0);
		glColor3d(1.0, 0.0, 1.0);
		makeboxROBOT( 3.4, 0.2, 0.2, GL_POLYGON  );//肩関節パーツ

			// 左手
			glPushMatrix();
				glTranslated(1.3, -0.5, 0.0);
				glTranslated(0.0, 0.5, 0.0);			
				
				glTranslated(0.0, -0.5, 0.0);
				glColor3d(0.0, 1.0, 0.0);
				makeboxROBOT( 0.5, 1.5, 0.5, GL_POLYGON  );//上腕パーツ				

				glTranslated(0.0, -0.5, 0.0);
				glColor3d(1.0, 0.0, 1.0);
				makeboxROBOT( 0.8, 0.2, 0.2, GL_POLYGON  );//肘関節パーツ

					glPushMatrix();				
						glTranslated(0.0, 0.0, 0.0);
						glRotated(-40.0, 1.0, 0.0, 0.0);				
						
						glTranslated(0.0, -0.5, 0.0);
						glColor3d(0.0, 0.8, 0.0);
						makeboxROBOT( 0.6, 1.6, 0.7, GL_POLYGON  );//腕パーツ	

						glTranslated(0.0, -0.9, 0.0);
						glColor3d(1.0, 1.0, 0.0);
						makeboxROBOT( 0.5, 0.7, 0.5, GL_POLYGON );//手パーツ	
					glPopMatrix();
			glPopMatrix();

			// 右手
			glPushMatrix();
				glTranslated(-1.3, -0.5, 0.0);
				glTranslated(0.0, 0.5, 0.0);
				
				glTranslated(0.0, -0.5, 0.0);
				glColor3d(0.0, 1.0, 0.0);
				makeboxROBOT( 0.5, 1.5, 0.5, GL_POLYGON  );//上腕パーツ				

				glTranslated(0.0, -0.5, 0.0);
				glColor3d(1.0, 0.0, 1.0);
				makeboxROBOT( 0.8, 0.2, 0.2, GL_POLYGON  );//肘関節パーツ

					glPushMatrix();				
						glTranslated(0.0, 0.0, 0.0);
						glRotated(-40.0, 1.0, 0.0, 0.0);
									
						glTranslated(0.0, -0.5, 0.0);
						glColor3d(0.0, 0.8, 0.0);
						makeboxROBOT( 0.6, 1.6, 0.7, GL_POLYGON );//腕パーツ	

						glTranslated(0.0, -0.9, 0.0);
						glColor3d(1.0, 1.0, 0.0);
						makeboxROBOT( 0.5, 0.7, 0.5, GL_POLYGON );//手パーツ	
					glPopMatrix();
			glPopMatrix();
		glPopMatrix();


		
		// 右足
		glPushMatrix();
				glTranslated(-0.6, -1.2, 0.0);
				glTranslated(0.0, 0.5, 0.0);

				glRotated(-10.0, 1.0, 0.0, 0.0);
				
				
				glTranslated(0.0, -0.5, 0.0);
				glColor3d(0.0, 1.0, 0.0);
				makeboxROBOT( 0.5, 1.5, 0.5, GL_POLYGON );//腿パーツ				

				glTranslated(0.0, -0.5, 0.0);
				glColor3d(1.0, 0.0, 1.0);
				makeboxROBOT( 0.8, 0.2, 0.2, GL_POLYGON );//膝関節パーツ


					glPushMatrix();				
						glTranslated(0.0, 0.0, 0.0);
						glRotated(20.0, 1.0, 0.0, 0.0);
						
						
						glTranslated(0.0, -0.5, 0.0);
						glColor3d(0.0, 0.8, 0.0);
						makeboxROBOT( 0.6, 1.6, 0.7, GL_POLYGON );//脛パーツ	

						glTranslated(0.0, -0.9, 0.0);
						glColor3d(1.0, 0.0, 1.0);
						makeboxROBOT( 0.5, 0.7, 0.5, GL_POLYGON );//足首パーツ

						glTranslated(0.0, -0.5, 0.3);
						glColor3d(1.0, 1.0, 0.0);
						glRotated(10.0, 1.0, 0.0, 0.0);
						makeboxROBOT( 0.7, 0.6, 1.4, GL_POLYGON );//足パーツ

					glPopMatrix();
			glPopMatrix();
					
		// 左足
		glPushMatrix();
				glTranslated(0.6, -1.2, 0.0);
				glTranslated(0.0, 0.5, 0.0);

				glRotated(-10.0, 1.0, 0.0, 0.0);

				glTranslated(0.0, -0.5, 0.0);
				glColor3d(0.0, 1.0, 0.0);
				makeboxROBOT( 0.5, 1.5, 0.5, GL_POLYGON );//腿パーツ				

				glTranslated(0.0, -0.5, 0.0);
				glColor3d(1.0, 0.0, 1.0);
				makeboxROBOT( 0.8, 0.2, 0.2, GL_POLYGON );//膝関節パーツ

					glPushMatrix();				
						glTranslated(0.0, 0.0, 0.0);
						glRotated(20.0, 1.0, 0.0, 0.0);
							
						glTranslated(0.0, -0.5, 0.0);
						glColor3d(0.0, 0.8, 0.0);
						makeboxROBOT( 0.6, 1.6, 0.7, GL_POLYGON );//脛パーツ	

						glTranslated(0.0, -0.9, 0.0);
						glColor3d(1.0, 0.0, 1.0);
						makeboxROBOT( 0.5, 0.7, 0.5, GL_POLYGON );//足首パーツ

						glTranslated(0.0, -0.5, 0.3);
						glColor3d(1.0, 1.0, 0.0);
						glRotated(10.0, 1.0, 0.0, 0.0);
						makeboxROBOT( 0.7, 0.6, 1.4, GL_POLYGON );//足パーツ
					glPopMatrix();
			glPopMatrix();
	glPopMatrix();
	glEndList();
}
