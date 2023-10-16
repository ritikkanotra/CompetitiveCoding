package Digital;
import java.util.*;
import java.util.stream.Collectors;
public class StreamAPI {

	public static void main(String[] args) {
		List<Integer> arr = Arrays.asList(1,2,3,4,5,6,7,8,9);
		
		//square each element of list
		List<Integer> res = arr.stream()
								.map(n-> n*n*n)
								.collect(Collectors.toList());
		
		System.out.println(res);
		
		//average of list
		OptionalDouble doubleAvg = arr.stream()
										.mapToDouble(Integer::doubleValue)
										.average();
		System.out.println(doubleAvg);
		
		//max in all even number in list
		int max = arr.stream().filter(n->n%2 ==0).max(Integer::compare).get();
		System.out.println("max: " + max);
		
		//sum of all elements in list
		int sum = arr.stream()
						.mapToInt(Integer::intValue)
						.sum();
		System.out.println("totalsum: " + sum);
		
		//sum of only even number in that list
		int evenOnlySum = arr.stream()
								.filter(n -> n%2 == 0)
								.mapToInt(Integer::intValue)
								.sum();
		System.out.println("evenOnlySum: "  + evenOnlySum);
		
		
		List<String> str = Arrays.asList("apple", "anda", "banana", "cherry", "date");
		
		//concatinating all words with "<->" and returning list
		String result = str.stream()
							.collect(Collectors.joining("<->"));
		System.out.println(result);
		
		//count all words whose length is 5 
		long count = str.stream()
						.filter(s -> s.length() == 5)
						.count();
		System.out.println(count);
		
		//group by words with there start alpha
		Map<Character, List<String>> letterCounts = str.stream()
												.collect(Collectors.groupingBy(
															fruit -> fruit.charAt(0),
															Collectors.toList()
														));
		
		System.out.println(letterCounts);

		//group by words with there start alpha
		Map<Character, Long> letterWords = str.stream()
												.collect(Collectors.groupingBy(
															fruit -> fruit.charAt(0),
															Collectors.counting()
												));
		System.out.println(letterWords);
		
		//all distinct elements in reverse sorted order		
		List<Integer> duplicates = Arrays.asList(2,2,2,3,5,53,43,5,2,43,54,5,14,44,4,4);
		List<Integer> distinct = duplicates.stream()
												.distinct()
												.sorted((a,b)->b-a)
												.collect(Collectors.toList());
		System.out.println(distinct);
										
	}

}
