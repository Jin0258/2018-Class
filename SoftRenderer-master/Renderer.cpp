
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


void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	// Draw
	SetColor(255, 0, 0);
	PutPixel(0, 0);

	//Circle
	SetColor(100, 255, 42);

	Vector2 Center(0.0f, 0.0f); //Vector2 ����ü�� �̿�

	Matrix2 Scaler;
	Scaler.SetScale(1.5f, 2.0f); //��ĺ�ȯ
	
	static float angle = 0.0f; //�� �ѹ��� ����
	angle += 0.1f; //�����Ӹ��� 0.1�� ����
	
	Matrix2 Rotator;
	Rotator.SetRotate(angle);
	int radius = 100.0f;
	for (int w = -radius; w < radius; w++)
	{
		for (int h = -radius; h < radius; h++)
		{
			Vector2 CurrentPos(w, h);
			if (Vector2::Dist(Center, CurrentPos) < radius) //Vector.cpp ���� ������ Dist�Լ��� ����Ͽ� ���
			{
				//PutPixel(w, h);
//				CurrentPos = CurrentPos * Scaler;
				Vector2 temp(CurrentPos.X - 50.0f, CurrentPos.Y - 15.0f);//���� ���� (0.0) -> (50.0f, 15.0f)
				Vector2 Rotated = temp * Rotator;
				PutPixel(Rotated.X, Rotated.Y);

			}
		}
	}

	//Triangle
	SetColor(255, 100, 42);

	
	// Buffer Swap 
	BufferSwap();
}
