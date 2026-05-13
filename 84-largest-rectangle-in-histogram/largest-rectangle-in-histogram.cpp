class Solution {
private:

    vector<int> rightIndex(vector<int>& heights){

        stack<int> s;
        vector<int> rightAns(heights.size());

        for(int i = heights.size()-1; i>=0; i--){

            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                rightAns[i] = heights.size();
            }
            else{
                rightAns[i] = s.top();
            }

            s.push(i);
        }

        return rightAns;
    }

    vector<int> leftIndex(vector<int>& heights){

        stack<int> s;
        vector<int> leftAns(heights.size());

        for(int i = 0; i<heights.size(); i++){

            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                leftAns[i] = -1;
            }
            else{
                leftAns[i] = s.top();
            }

            s.push(i);
        }

        return leftAns;
    }

public:

    int largestRectangleArea(vector<int>& heights) {

        vector<int> rightAns = rightIndex(heights);
        vector<int> leftAns = leftIndex(heights);

        int area = 0;

        for(int i = 0; i<heights.size(); i++){

            int width = rightAns[i] - leftAns[i] - 1;

            int newArea = heights[i] * width;

            area = max(area, newArea);
        }

        return area;
    }
};