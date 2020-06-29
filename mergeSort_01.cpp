#include<bits/stdc++.h>
using namespace std;



void merging(int arr[],int startPoint, int midPoint, int endPoint)
{
    int firstArrCnt,secArrCnt,i;
    firstArrCnt = startPoint;
    secArrCnt = midPoint + 1;
    
    int temp[endPoint];

    for(i = firstArrCnt; firstArrCnt<=midPoint && secArrCnt<=endPoint; i++)
    {
        if(arr[firstArrCnt] < arr[secArrCnt])
            temp[i] = arr[firstArrCnt++];
        else
            temp[i] = arr[secArrCnt++];
    }

    while(firstArrCnt <= midPoint)
        temp[i++] = arr[firstArrCnt++];

    while(secArrCnt <= endPoint)
        temp[i++] = arr[secArrCnt++];

    for(i = startPoint; i<=endPoint; i++)
        arr[i] = temp[i];

}

void sorting(int arr[], int startPoint, int endPoint)
{
    int midPoint;

    if(startPoint >= endPoint)
        return;

    //printf("Counter: %d: Start: %d, End: %d\n",++counter, startPoint, endPoint);

    midPoint = (startPoint+endPoint)/2;

    sorting(arr,startPoint, midPoint);
    sorting(arr,midPoint+1, endPoint);

    merging(arr,startPoint, midPoint, endPoint);
    
    
}

int main()
{
    int i, n;
    
    printf("Enter size of array : \n");
    
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter "<<n<<" elements :\n";

    for(i=0; i<n; i++)
        cin>>arr[i];

    sorting(arr,0, n-1);

    printf("\nAfter sorting the Array:\n");
    for(i = 0; i<n; i++)
    {
    	cout<<arr[i];
        cout<<"\n";
	}
        

    return 0;
}
