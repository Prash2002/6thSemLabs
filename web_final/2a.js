//  Write a java script program to convert month number to month name using closures.
// ● If the user enters a number less than 1 or greater than 12 or a non-number, have the function write "Bad
// Number" in the monthName field.
// ● If the user enters a decimal between 1 and 12 (inclusive), strip the decimal portion of the number

function calculate(n) {
  var months = [
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sept",
    "Oct",
    "Nov",
    "Dec",
  ];
  var return_month = function () {
    if (n < 1 || n > 12 || isNaN(n)) return "Bad string";
    n = Math.floor(n);
    return months[n - 1];
  };
  return return_month;
}

var jan = calculate(1);
console.log(jan());

var jul = calculate(7);
console.log(jul());

var outlier = calculate(17);
console.log(outlier());

var flo = calculate(8.7);
console.log(flo());
