/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 
int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;//从小到大
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //排序，夹逼法
    *returnSize = 0; 
    if (numsSize == 0) return 0;
    int * rst = (int*)malloc(sizeof(int) * 2);
    int* numscpy = (int*)malloc(sizeof(int) * numsSize);
    memcpy(numscpy, nums, sizeof(int) * numsSize);//存原数组，因为要返回下标

    qsort(nums, numsSize, sizeof(int), comp);

    bool succFlag = false;
    int i = 0, j = numsSize - 1;
    while(i < j) {  
        if (nums[i] + nums[j] != target) {
            nums[i] + nums[j] < target ? i++ : j--;
        }
        else{
            *returnSize = 2;
            succFlag = true;
            break;
        }   
    };
    if (succFlag == false) return 0;

    unsigned char m = 0;//注意rst中两数相等的测试用例
    for (int k = 0; k < numsSize; k++) {
        if (numscpy[k] == nums[i] || numscpy[k] == nums[j]) {
            rst[m++] = k;
        }
    }
    return rst;

}





// @lc code=end

