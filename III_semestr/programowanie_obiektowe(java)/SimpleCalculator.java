package kol2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator extends JFrame {
    private JTextField textField1, textField2, resultField;
    private JComboBox<String> operationComboBox;

    public SimpleCalculator() {
        setTitle("Prosty Kalkulator");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        initComponents();
    }

    private void initComponents() {
        // Panel główny
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(3, 3));

        // Miejsce na pierwszą liczbę
        textField1 = new JTextField();
        mainPanel.add(new JLabel("Liczba 1:"));
        mainPanel.add(textField1);

        // Miejsce na drugą liczbę
        textField2 = new JTextField();
        mainPanel.add(new JLabel("Liczba 2:"));
        mainPanel.add(textField2);

        // Wybór operacji
        String[] operations = {"Dodawanie", "Odejmowanie", "Mnożenie", "Dzielenie"};
        operationComboBox = new JComboBox<>(operations);
        mainPanel.add(new JLabel("Działanie:"));
        mainPanel.add(operationComboBox);

        // Przycisk do obliczeń
        JButton calculateButton = new JButton("Oblicz");
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculate();
            }
        });
        mainPanel.add(calculateButton);

        // Pole wyniku
        resultField = new JTextField();
        resultField.setEditable(false);
        mainPanel.add(new JLabel("Wynik:"));
        mainPanel.add(resultField);

        add(mainPanel);
    }

    private void calculate() {
        try {
            double num1 = Double.parseDouble(textField1.getText());
            double num2 = Double.parseDouble(textField2.getText());
            String operation = (String) operationComboBox.getSelectedItem();
            double result = 0;

            switch (operation) {
                case "Dodawanie":
                    result = num1 + num2;
                    break;
                case "Odejmowanie":
                    result = num1 - num2;
                    break;
                case "Mnożenie":
                    result = num1 * num2;
                    break;
                case "Dzielenie":
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        JOptionPane.showMessageDialog(this, "Nie można dzielić przez zero!", "Błąd", JOptionPane.ERROR_MESSAGE);
                        return;
                    }
                    break;
            }

            resultField.setText(Double.toString(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Wprowadź poprawne liczby!", "Błąd", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SimpleCalculator().setVisible(true);
            }
        });
    }
}
