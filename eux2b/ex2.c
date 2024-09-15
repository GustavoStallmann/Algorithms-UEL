#include <stdio.h>

int main() {  
   int nums[6];
   int high;

   for(int i = 0; i < 6; i++) {
    scanf("%d", &nums[i]);

    if(i == 0) 
        high = i;

    else if(nums[high] < nums[i]) {
         high = i;
    }
   }
    
   nums[high] = nums[high] - nums[high] - nums[high];


   for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {    
        if (i == j) continue;
            
        if(nums[i] + nums[j] == nums[high] - nums[high] - nums[high]) {
             nums[i] = -1;
             nums[j] = -1;
        }    
    
        
    }
   }
    
   int count = 0;
   int total = 0;
    
   for(int i = 0; i < 6; i++) {
        if (nums[i] >= 0) {
            total+=nums[i];
            count++;
        }

        
        if(count > 3 || total > (nums[high] - nums[high] - nums[high])) {
            printf("N");
            return 0;
        }
   }
    
  if (total == (nums[high] - nums[high] - nums[high]) && count == 3) {
      printf("S");
  } else {
      printf("N");
  }
  
  return 0;

}
