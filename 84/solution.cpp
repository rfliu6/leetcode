class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ascending;       
        ascending.push(-1);          
        int result = 0;
        heights.push_back(0);         // clear the stack in the last for loop
        
        for(int i=0; i<heights.size(); i++){           
          while(ascending.top() != -1 && heights[i] <= heights[ascending.top()]){          
          // only keep heights in ascending order, pop heights <= current one
              int h = heights[ascending.top()];   // heights of current retangle
              ascending.pop();    //previous index is the left boundary - 1 of current rectangle
              result = max(result, (i-ascending.top()-1)*h);     //i is the right boundary + 1 of current rectangle
                                                                  // right-left+1 = i-ascending.top()-1
          }
          ascending.push(i); //ascending order stack
        }
        return result;
    }
};
