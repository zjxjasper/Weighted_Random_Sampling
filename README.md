# Weighted_Random_Sampling
a simple weighted random sampling algorithm in c++

WRS.inp is the input file:
first line, int n:  number of total generationed numbers
second line: weight function array for each type

output: 
current count on each type

algorithm:
generate a random number from (0-1), use binary search to get the type (based on input weight function),
e.g. w = [0.1,0.4,0.5] : [0 - 0.1) -> 0;  (0.1 - 0.5] -> 1; (0.5, 1) -> 2

if the count of the type of the generated random integer is more than its assigned weight, this generation is declined and regenerate until accept.
e.g. w = [0.1,0.4,0.5], current count [1,0,0],  if generated value is 0, declined; if genearted value is 1 or 2, accepted.

the time complexity of generate N item sample is amortized O(N).
