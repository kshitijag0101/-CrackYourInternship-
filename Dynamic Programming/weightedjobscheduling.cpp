// C++ program for weighted job scheduling using Dynamic
// Programming.
#include <algorithm>
#include <iostream>
using namespace std;

// A job has start time, finish time and profit.
struct Job {
	int start, finish, profit;
};

bool jobcmp(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]
int latestNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}
int findMaxProfit(Job arr[], int n)
{
	sort(arr,arr+n,jobcmp);
    int dp[n];
    dp[0]=arr[0].profit;
    int count=1;
    for(int i=1;i<n;i++){
        int pro=arr[i].profit;
        int l=latestNonConflict(arr,i);
        if(l!=-1){
            pro+=dp[l];
        }
        if(pro>=dp[i-1]){
            count++;
            dp[i]=pro;
        }
        else{
            count=1;
            dp[i]=dp[i-1];
        }
    }
    return dp[n-1];
}

// Driver program
int main()
{
	Job arr[] = { { 3, 10, 20 },
				{ 1, 2, 50 },
				{ 6, 19, 100 },
				{ 2, 100, 200 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The optimal profit is "
		<< findMaxProfit(arr, n);
	return 0;
}
