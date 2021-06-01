

/*
    arr a = priceOfJeans = [3, 4]
    arr b = priceOfShoes = [4]
    arr c = priceOfSkirts = [2, 3]
    arr d = priceOfTops = [1, 2]


    budgeted = 10 

    1. Sort all arrays
    2. Now, all the first elements are the ones which I want. (At least 1 should be there from each array)
    
    3. {3, 4, 2, 1} (SUM = 10) - difference = budget - sum_of_current_elements = 1, num_of_combinations = 1 + (how many elements found which have the value 'difference' more than current element of that array)
    4. After the first array is formed.
    5. We have to find all the elements in all arrays, which are 'difference' more than the current element chosen in that respective array.

    // till now we have difference and num_of_combinations
    // traversing array a
    for(int i = 1; i < a.size(); i++) {             o(n)

        if(a[i] - a[0] == difference) {
            num_of_combinations += 1;               k
        }
    }

    // traverse simililarly for all arrays.




    
    Complexity Calculation - 

    for(0-n) {          o(n)
        addition        k (constant which is almost negligible)
    }

    for(0->n) {         o(n) // Array of objects, and you have to sort on the basis of some unique id

        sort();         o(logn)             o(n) * o(logn) > o(n)
    }

    for(0->n) {         o(n)                o(n) * o(n)  = o(n2)
        for(0->n) {     o(n)   
            addition;   o(k)
        }
    }


    
    arr[1000]
*/

/*
    given:
    arr[n]
    query[m]

    n = 10, m = 3 (For given stock data of 10 days, query is for 3 days)

    stockData = [5, 6, 8, 4, 9, 10, 8, 3, 6, 4]
    queries = [6, 5, 4]

    // Array for the answers
    int ans;
    int k = 0;
    int n = stockData.size();

    // Iterating the query array
    for(int i = 0; i<queries.size(); i++) {
        
        // We have to fetch data of this day
        int day = queries[i];

        // day 1 means index 0, day 2 means index 1...
        int value_at_that_day = stockData[day - 1];


        // Find nearest day on which stock price is smaller than given day
        bool condition = false;

        // When our required condition is met, we make condition true, and stop the loop.
        // Using while loop to avoid unnecessary calculations



        int forward_iterator = day if day < n else n;
        int backward_iterator = (day - 2) if (day-2) > 0 else 0;

       while condition!=1 :

        if(fwd_i == n && bck_i == 0) {
            ans.append(-1);
            break;
        }

        if(stockData[fwd_i] < value_day && stockData[bck_i] < value_day) {
            ans.append(bck_i + 1)
            break;
        }

        if(stockData[fwd_i] < value_day || stockData[bck_i] < value_day) {
            lower_index = fwd_i if (stockData[fwd_i] < value_day) else bck_i
            ans.append(lower_index + 1);
            break;
        }

        else {

            // fwd_i should be less than n and bck_i should be greater than 0
            if(fwd_i == n) {
                fwd_i = n;
            }
            else {
                fwd_i++;
            }

            if(bck_i == 0) {
                bck_i = 0;
            }
            else {
                bck_i--;
            }
        }
    }
    return ans;



    // sort the stockData array, but we have to keep in mind the days it represents
    stockData = [5, 6, 8, 4, 9, 10, 8, 3, 6, 4]
    map = [{1,5}, {2,6}, {} ...]



    // Map with day number and value at that day
    for i in range len(stockData):
        stockMap = map(i+1, stockData[i])
    
    // Sorting map by values, so lower value will come first
    sortedStockMap = sorted(stockMap.items(), key=lambda kv: kv[1])

    // Cannot sort the queries

    // Sorting on the basis of value of stock will give me a shorter
    // iteration in the loop


    def predictAnswer(stockData, queries):

        // Map with day number and value at that day
        for i in range len(stockData):
            stockMap = map(i+1, stockData[i])
    
        // Sorting map by values, so lower value will come first
        sortedStockMap = sorted(stockMap.items(), key=lambda kv: kv[1])

        ans=[]
        k=0
        n = len(stockData) - 1
        for val in queries:
            day=val
            value_day = sortedData[day - 1]
            condition = 0
            if day <= n:
                fwd_i = day
            else:
                fwd_i=n
            
            if day - 2 >= 0:
                bck_i=day-2
            else:
                bck_i=0
            
            while condition!=1:
                

            
            

    

*/
