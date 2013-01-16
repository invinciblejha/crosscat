#ifndef GUARD_continuouscomponentmodel_h
#define GUARD_continuouscomponentmodel_h

#include <iomanip> // std::setprecision
#include "ComponentModel.h"
#include "numerics.h"
#include "utils.h"

class ContinuousComponentModel : public ComponentModel {
 public:
  ContinuousComponentModel(std::map<std::string, double> &in_hyper_hash);
  //
  // getters
  void get_hyper_doubles(double &r, double &nu, double &s, double &mu) const;
  void get_suffstats(int &count_out, double &sum_x, double &sum_x_sq) const;
  //
  // calculators
  double calc_marginal_logp() const;
  double calc_element_predictive_logp(double element) const;
  std::vector<double> calc_hyper_conditionals(std::string which_hyper,
					      std::vector<double> hyper_grid) const;
  //
  // mutators
  double insert_element(double element);
  double remove_element(double element);
  double incorporate_hyper_update();
 protected:
  void set_log_Z_0();
  void init_suffstats();
 private:
};

void print_defaults();

#endif // GUARD_continuouscomponentmodel_h
