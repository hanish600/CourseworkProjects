function processEmployees(employees) {
  for (var i = 0; i < employees.length; i++) {
    var employee = employees[i];
    var gross_salary = employee.gross_salary;
    var net_salary = employee.computeNetSalary(gross_salary);

    console.log(net_salary);
  }
}

var employees = [
  {
    name: "Sam",
    gross_salary: 70000,
    getNetSalary: function (gross_salary) {
      return gross_salary - gross_salary * 0.2;
    },
  },
  {
    name: "Bob",
    gross_salary: 80000,
    computeNetSalary: function (gross_salary) {
      return gross_salary - gross_salary * 0.2;
    },
  },
  {
    name: "Joe",
    gross_salary: 40000,
    computeNetSalary: function (gross_salary) {
      return gross_salary - gross_salary * 0.2;
    },
  },
];

try {
  processEmployees(employees); // FAILS
}
catch (err)
{
  console.log("catching ....");
  result="Error thrown";
  console.log(result);
}
