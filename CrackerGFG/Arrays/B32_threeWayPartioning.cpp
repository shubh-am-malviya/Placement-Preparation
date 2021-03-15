void threeWayPartition(vector<int>& array,int a, int b)
{
    int left = -1, right = array.size();
    
    int i = 0;
    
    while (i < right) {
        
        if (array[i] < a) {
            left++;
            swap(array[i], array[left]);
        } 
        else if (array[i] > b) {
            right--;
            swap(array[right], array[i]);
            continue;
        }
        
        i++;
        
    }
}
