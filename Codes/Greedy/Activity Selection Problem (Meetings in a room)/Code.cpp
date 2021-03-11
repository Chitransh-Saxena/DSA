/*
    Given the start and end time array of meetings to be held, find the maximum number of meetings that can be held in that room
    1. Start by making a vector of a struct (start_time, end_time, pos). pos is basically index + 1
    2. For the meetings that are taking less time, check if end_time_of_last_meeting < start_time_of_next_meeting 
    3. Add them in a vector. (Choosing a vector because we need to keep track of last_end_time at each meeting)
*/

// Hold the start time, end time and the meeting number
struct meeting {
    int start;
    int end;
    int pos;
    
    // This pointer was necessary otherwise values in vector were all garbage
    // Investigate how did this pointer sort that out???????
    meeting(int start_, int end_, int pos_) {
        this->start = start_;
        this->end = end_;
        this->pos = pos_;
    }
};

class Solution{
    public:
        int maxMeetings(int start[], int end[], int n) {
            
        // Creating a container to store the meetings sorted by end time
        vector<meeting> v;
        for(int i = 0; i < n; i++ ) {
            meeting m(start[i], end[i], i+1);
            v.push_back(m);
        }
        
        // Now sort the vector based on end_time
        // Why are we sorting based on end time?
        // Because - We are assuming that first item will be in our list of answers, so from there, we just keep on finiding nearest meeting that can finish,
        // That will be nothing but next meeting that can finish after first one ends, so we sort based on end_time but keep track of it's start time and position
        auto comp = [](meeting m1, meeting m2){
            return m1.end < m2.end;
        };
        sort(v.begin(), v.end(), comp);
        
        // First meeting will always be performed, end time will be limit of that meeting
        int count = 1;
        
        // Creating a vector to store which all meetings need to be processed
        vector<int> ans;
        // Since first meeting is always performed, adding it to the vector
        ans.push_back(v[0].pos);
        // limit will be used as end_time_of_last_meeting, so that we can check that start time of next is greater than this
        int limit = v[0].end;
        
            
       for(int i = 1; i < n; i++) {

            // In the question it was given that equality of end and start is not allowed, making this part clear 
            if(v[i].start > limit) {
                limit = v[i].end;
                ans.push_back(v[i].pos);
            }
        }
        
        return ans.size();
    }
    }
};
