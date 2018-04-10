
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Vector.h"
#include "Renderer.h"

bool IsInRange(int x, int y);
void PutPixel(int x, int y);

bool IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + x + g_nClientWidth * -y;
	*(dest + offset) = g_CurrentColor;
}

void DrawLine(Vector3 start, Vector3 dest)
{
	int length = ((dest - start).Dist());
	float inc = 1.0f / length;

	int maxLength = (float)length;
	for (int i = 0; i <= length; i++)
	{
		float t = inc * i;
		if (t >= length) t = length;
		Vector3 Pt = start * (1.0f - t) + dest * t;
		PutPixel(Pt.X, Pt.Y);
	}
}


void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	//// Draw
	//SetColor(255, 0, 0);
	//PutPixel(0, 0);

//	//Circle
//	SetColor(100, 255, 42);
//
//	Vector2 Center(0.0f, 0.0f); //Vector2 구조체를 이용
//
//	Matrix2 Scaler;
//	Scaler.SetScale(1.5f, 2.0f); //행렬변환
//	
//	static float angle = 0.0f; //딱 한번만 실행
//	angle += 0.1f; //프레임마다 0.1씩 증가
//	
//	Matrix2 Rotator;
//	Rotator.SetRotate(angle);
//	int radius = 100.0f;
//	for (int w = -radius; w < radius; w++)
//	{
//		for (int h = -radius; h < radius; h++)
//		{
//			Vector2 CurrentPos(w, h);
//			if (Vector2::Dist(Center, CurrentPos) < radius) //Vector.cpp 에서 정의한 Dist함수를 사용하여 계산
//			{
//				//PutPixel(w, h);
////				CurrentPos = CurrentPos * Scaler;
//				Vector2 temp(CurrentPos.X - 50.0f, CurrentPos.Y - 15.0f);//원점 변경 (0.0) -> (50.0f, 15.0f)
//				Vector2 Rotated = temp * Rotator;
//				PutPixel(Rotated.X, Rotated.Y);
//
//			}
//		}
//	}

	static Vector3 Origin1(10.0f, 10.0f, 1.0f);
	static Vector3 Origin2(80.0f, 20.0f, 1.0f);
	Vector3 Pt1, Pt2;
	Matrix3 Scalor,Translator,Rotator;

	float scale = 1.0f;
	float translate = 0.0f;
	float angle = 0.0f;
	
	Rotator.SetIdentity();
	Scalor.SetIdentity();
	Translator.SetIdentity();

	SetColor(255, 0, 0);

	if (GetAsyncKeyState(VK_LEFT)) //Translator
	{
		translate += 0.1f;
		Translator.SetTranslate(translate,0.0f);
		Origin1 = Origin1 * Translator;
		Origin2 = Origin2 * Translator;
	}
	if (GetAsyncKeyState(VK_RIGHT)) //Rotator
	{
		angle += 0.1f;
		Rotator.SetRotate(angle);
		Origin1 = Origin1 * Rotator;
		Origin2 = Origin2 * Rotator;
	}
	if (GetAsyncKeyState(VK_UP)) //Scalor
	{
		scale += 0.01f;
		Scalor.SetScale(scale);
		Origin2 = Origin2 * Scalor;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{		
		scale -= 0.01f;
		Scalor.SetScale(scale);
		Origin2 = Origin2 * Scalor;
	}

	DrawLine(Origin1, Origin2);

	// Buffer Swap 
	BufferSwap();
}
