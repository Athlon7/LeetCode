double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total, mid;

    total = nums1Size + nums2Size;
    mid = (int)(total / 2);
    
}


int findk(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (!nums1Size) return nums2[k-1];
    if (!nums2Size) return nums1[k-1];
    if (k==1) return (nums1[0]<nums2[0]) ? nums1[0] : nums2[0];
    if (nums1Size<k/2) return findk(nums1, nums1Size, nums2+k/2, nums2Size-k/2, k-k/2);
    if (nums2Size<k/2) return findk(nums1+k/2, nums1Size-k/2, nums2, nums2Size, k-k/2);
    if (nums1[k/2-1]>nums2[k/2-1]) {
        return findk(nums1, nums1Size, nums2+k/2, nums2Size-k/2, k-k/2);
    } else if (nums1[k/2-1]<nums2[k/2-1]) {
        return findk(nums1+k/2, nums1Size-k/2, nums2, nums2Size, k-k/2);
    } else {
        return (k&1) ? findk(nums1+k/2, nums1Size-k/2, nums2+k/2, nums2Size-k/2, 1) : nums1[k/2-1];
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    return (sum&1) ? findk(nums1, nums1Size, nums2, nums2Size, (sum+1)/2) : 
                    (findk(nums1, nums1Size, nums2, nums2Size, (sum+1)/2) + 
                     findk(nums1, nums1Size, nums2, nums2Size, (sum+2)/2))/2.0;
}