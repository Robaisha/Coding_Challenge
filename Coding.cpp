#include<iostream>
using namespace std;
bool isSafe(int arr[3][4],int x,int y,int n,int c){
	if(x<n && y<c && arr[x][y]==1){
		return true;
	}
	return false;
}
bool RatinAMaze(int arr[3][4],int x,int y,int n,int c,int **solArr){
	if((x==(n-1))&& (y==(c-1))){
		solArr[x][y]=1;
		return true;
	}
	if(isSafe(arr,x,y,n,c)){
		solArr[x][y]=1;
		if(RatinAMaze(arr,x+1,y,n,c,solArr)){
			return true;
		}
		if(RatinAMaze(arr,x,y+1,n,c,solArr)){
			return true;
		}
		solArr[x][y]=0;
		return false;
	}
	return false;
}
int main(){
	int arr[3][4] = { { 1, 1, 0, 1 },
      { 0, 1, 1, 1 },
      { 0, 1, 1, 1 }  
	 };
	 
	int** solArr=new int*[3];
	for(int i=0; i<3;i++){
		solArr[i]=new int[4];
		for(int j=0; j<4;j++){
		   solArr[i][j]=0;	
    	}
    }
    
	if(RatinAMaze(arr,0,0,3,4,solArr)){
		for(int i=0;i<3;i++){
			for(int j=0;j<4;j++){			
				cout<<solArr[i][j]<<" ";
			}
			cout<<endl;
			
		}
		
		
		
	}
	
	return 0;
	
}
