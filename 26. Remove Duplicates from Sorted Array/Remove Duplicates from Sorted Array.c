int removeDuplicates(int* nums, int numsSize)
{
   if(numsSize == 0)
    return 0;

   int i = 0, j = 0, cnt, temp = nums[0] + 1, size = numsSize;

   while(i < numsSize)
   {
        
        if(nums[i] == temp)
        {
            size--;
            i++;
        }
        else
        {
            nums[j++] = nums[i];
            temp = nums[i++];
        }
   } 

   return size;
}