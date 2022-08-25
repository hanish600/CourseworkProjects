module edu.csueastbay.cs401.calculator {
    requires javafx.controls;
    requires javafx.fxml;


    opens edu.csueastbay.cs401.calculator to javafx.fxml;
    exports edu.csueastbay.cs401.calculator;
}