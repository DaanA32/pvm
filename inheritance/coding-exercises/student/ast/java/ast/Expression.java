package ast;

import java.util.Map;

public interface Expression {
    double evaluate(Map<String, Double> context);
}
