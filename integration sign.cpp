#include <iostream>
#include <gsl/gsl_integration.h>

double f(double x, void *params) {
    return x*x;
}

int main() {
    gsl_integration_workspace *w = gsl_integration_workspace_alloc(1000);
    double result, error;
    gsl_function F;
    F.function = &f;

    gsl_integration_qags(&F, 0, 1, 0, 1e-7, 1000, w, &result, &error);
    std::cout << "∫_0^1 x^2 dx = " << result << std::endl;
    gsl_integration_workspace_free(w);
    return 0;
}
