package edu.csueastbay.cs401.calculator;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

import java.util.ArrayList;

public class CalculatorController {

    // Stores input and operation
    ArrayList<Double> data = new ArrayList<Double>();
    // iterates input and operator
    int i=0;
    ArrayList<Integer> operation = new ArrayList<Integer>();
    @FXML
    private TextField Solution;

    @FXML
    private Button clearAll;

    @FXML
    private Button clearCurrent;

    @FXML
    private Button divide;

    @FXML
    private Button dot;

    @FXML
    private Button eight;

    @FXML
    private Button equals;

    @FXML
    private Button five;

    @FXML
    private Button four;

    @FXML
    private Button minus;

    @FXML
    private Button negate;

    @FXML
    private Button nine;

    @FXML
    private Button one;

    @FXML
    private Button plus;

    @FXML
    private Button seven;

    @FXML
    private Button six;

    @FXML
    private Button three;

    @FXML
    private Button times;

    @FXML
    private Button two;

    @FXML
    private Button zero;

    @FXML
    void handlePress(ActionEvent event) {
        if (event.getSource() == dot)
        {
            Solution.setText(Solution.getText() + ".");
        }
        if (event.getSource() == zero)
        {

            Solution.setText(Solution.getText() + "0");
        }
        else if (event.getSource() == one) {
            Solution.setText(Solution.getText() + "1");
        }
        else if (event.getSource() == two)
        {
            Solution.setText(Solution.getText() + "2");
        }
        else if (event.getSource() == three)
        {
            Solution.setText(Solution.getText() + "3");
        }
        else if (event.getSource() == four)
        {
            Solution.setText(Solution.getText() + "4");
        }
        else if (event.getSource() == five)
        {
            Solution.setText(Solution.getText() + "5");
        }
        else if (event.getSource() == six)
        {
            Solution.setText(Solution.getText() + "6");
        }
        else if (event.getSource() == seven)
        {
            Solution.setText(Solution.getText() + "7");
        }
        else if (event.getSource() == eight)
        {
            Solution.setText(Solution.getText() + "8");
        }
        else if (event.getSource() == nine)
        {
            Solution.setText(Solution.getText() + "9");
        }
        else if (event.getSource() == clearCurrent)
        {
            int size=Solution.getLength()-1;
            String newString=Solution.getText().substring(0,size);
            Solution.setText(newString);
        }
        else if (event.getSource() == clearAll)
        {
            Solution.setText("");
        }
        else if (event.getSource() == negate) {
            // String contains negative, so replace it with positive
            if (Solution.getText().contains("-"))
            {
                Solution.setText(Solution.getText().replace("-","+"));
            }
            // String is empty, so positive value is assumed
            // negate it
            else if (Solution.getText() == "")
            {
                Solution.setText("-");
            }
            // String is not a negative or positive or empty,
            // so take the value and negate it
            else if (!Solution.getText().contains("+"))
            {
                double Negate = Double.parseDouble(Solution.getText());
                Negate*=-1;
                Solution.setText(String.valueOf(Negate));
            }
            // Solution is positive
            // so replace it with negative
            else
            {
                Solution.setText(Solution.getText().replace("+","-"));
            }

        }
        else if (event.getSource() == plus)
        {
            data.add(Double.parseDouble(Solution.getText()));
            operation.add(1); // Add
            Solution.setText("");
        }
        else if (event.getSource() == minus)
        {

            data.add(Double.parseDouble(Solution.getText()));
            operation.add(2); // Sub
            Solution.setText("");
        }
        else if (event.getSource() == divide)
        {
            data.add(Double.parseDouble(Solution.getText()));
            operation.add(3); // Div
            Solution.setText("");
        }
        else if (event.getSource() == times)
        {
            data.add(Double.parseDouble(Solution.getText()));
            operation.add(4); // multiply
            Solution.setText("");
        }
        else if (event.getSource() == equals)
        {
            // Stores last input
            data.add(Double.parseDouble(Solution.getText()));
            int j=1;
            double ans=data.get(i);
            for (int i=0;i<operation.size();++i)
            {
                // adds previous and next val
                if (operation.get(i) == 1)
                {
                    ans= (ans+data.get(j++));
                }
                // subs previous and next val
                else if (operation.get(i) == 2)
                {
                    ans= (ans-data.get(j++));
                }
                // divides previous and next val
                else if (operation.get(i) == 3)
                {
                    ans= (ans/data.get(j++));
                }
                // multiplies prev and next val
                else if (operation.get(i) == 4)
                {
                    ans= (ans*data.get(j++));
                }
            }
            Solution.setText(String.valueOf(ans));
        }
    }

}
