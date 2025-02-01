#include <iostream>
using namespace std;
int main()
{
	int rank,row;
	cin>>row>>rank;
	int arr[row][rank];
	bool via[row][rank];
	for(int i=0;i<row;i++)//二维数组依次接收数字
	{
		for(int j=0;j<rank;j++)
		{
			cin>>arr[i][j];
			via[i][j] = 0;
		}
	}
	int x=0,y=0,time=0;
	int direction=0;
	cout<<arr[0][0];
	via[0][0]=1;
	
	while(time<=2*row*rank)//设置循环次数
	{
		time++;
		if(direction == 0)//方向下
		{
			if(x+1<row && via[x+1][y]==0)//判定，坐标是否在行/列之内并且是否被调用过
			{
				cout<<' '<<arr[x+1][y];
				via[x+1][y] = 1;
				x++;
			}
			else
			{
				direction++;//下一个方向
			}
		}
		
		
		if(direction == 1)//方向右
		{
			if(y+1<rank && via[x][y+1]==0)
			{
				cout<<' '<<arr[x][y+1];
				via[x][y+1] = 1;
				y++;
			}
			else
			{
				direction++;
			}
		}
		
		
		if(direction == 2)//方向上
		{
			if(x-1>=0 && via[x-1][y]==0)
			{
				cout<<' '<<arr[x-1][y];
				via[x-1][y] = 1;
				x--;
			}
			else
			{
				direction++;
			}
		}
		
		
		if(direction == 3)//方向左
		{
			if(y-1>=0 && via[x][y-1]==0)
			{
				cout<<' '<<arr[x][y-1];
				via[x][y-1] = 1;
				y--;
			}
			else
			{
				direction = 0;//形成闭环
			}
		}
		
	}
	
	return 0;
}
