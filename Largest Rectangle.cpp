  int largestRectangle(vector<int>& heights) {
    int maxarea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        int minheight = heights[i]; // Initialize minheight with the current bar's height
        for (int j = i; j < n; j++) {
            if(minheight>heights[j]) minheight = heights[j];
            int area = minheight * (j - i + 1);
            if(maxarea<area) maxarea =  area;
        }
    }

    return maxarea;
}

