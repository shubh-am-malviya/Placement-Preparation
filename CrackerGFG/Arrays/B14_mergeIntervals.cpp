// (I) Sort the intervals
// (II) insert first interval in the result variable
// (III) Iterate over the intervals and compare them with last interval in the result
//     (i) If the interval overlaps with the last interval in the result, then update the last interval in the result
//     (ii) If it doesn't overlaps with the last interval, then push_back the interval in the result




vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());                                       // I
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);                                                 // II
    
    for (vector<int> v: intervals) {                                                // III
        
        if (result[result.size()-1][1] >= v[0]) {                                   // (i)
            result[result.size()-1][1] = max(result[result.size()-1][1], v[1]);     
        } else {
            result.push_back(v);                                                    // (ii)
        }
    }
    
    return result;
}
