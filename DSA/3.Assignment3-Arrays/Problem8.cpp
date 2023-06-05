// Question 8
// Given an array of meeting time intervals where intervals[i] = [starti, endi],
// determine if a person could attend all meetings.

// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

void maxMeetings(int s[], int f[], int N)
{
    pair<int, int> a[N + 1];
    int i;
    for (i = 0; i < N; i++) {
        a[i].first = f[i];
        a[i].second = i;
    }
   
    // Sorting of meeting according to their finish time.
    sort(a, a + N);
 
    // Time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = a[0].first;
 
    // Vector for storing selected meeting.
    vector<int> m;
 
    m.push_back(a[0].second + 1);
 
    for (i = 1; i < N; i++) {
        if (s[a[i].second] > time_limit) {
            // Push selected meeting to vector
            m.push_back(a[i].second + 1);
 
            // update time limit
            time_limit = a[i].first;
        }
    }
 
    // Print final selected meetings.
    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
}