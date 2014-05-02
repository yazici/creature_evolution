#ifndef SETTINGSMANAGER
#define SETTINGSMANAGER
#ifdef _WIN32
  #define M_PI 3.14159265359
#endif

//C++
#include <iostream>
#include <vector>
// External
#include "vec3.h"
#ifndef Q_MOC_RUN
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#endif

// class Creature;
// class Body;
// class Brain;

//! Class to handle all the settings in the program. Can only instance one SettingsManager-class in the whole program. 
class SettingsManager {
public:
  static SettingsManager* Instance();

  int GetPopulationSize();
  int GetMaxGenerations();
  float GetCrossover();
  float GetElitism();
  float GetMutation();
  float GetMutationInternal();
  float GetMutationSigma();

  int GetFrameWidth();
  int GetFrameHeight();
  float GetRotationSensitivity();

  Vec3 GetMainBodyDimension();

  void SetPopulationSize(int population_size);
  void SetMaxGenerations(int max_generations);
  void SetCrossover(float crossover_ratio);
  void SetElitism(float elitism_ratio);
  void SetMutation(float mutation_ratio);
  void SetMutationInternal(float mutation_ratio_internal);
  void SetMutationSigma(float mutation_sigma);

  void SetFrameWidth(int frame_width);
  void SetFrameHeight(int frame_height);
  void SetRotationSensitivity(float sense);

  void SetCreatureType(int creature);
  int GetCreatureType();

  void SetFitnessDistanceForward(float dist);
  float GetFitnessDistanceForward();
  void SetFitnessMaxHeight(float height);
  float GetFitnessMaxHeight();
  void SetFitnessEnergy(float energy);
  float GetFitnessEnergy();

  // void AddBestCreature(Creature creature);
  // Creature GetBestCreature();
  // std::vector<Creature> GetAllBestCreatures();

  void SetMainBodyDimension(Vec3 dimension);

private:
  SettingsManager();
  ~SettingsManager(void); 
  // Evolution settings
  int population_size_;
  int max_generations_;
  float crossover_ratio_;
  float elitism_ratio_;

  float mutation_ratio_;
  float mutation_ratio_internal_;
  float mutation_sigma_;

  // Render settings
  int frame_width_;
  int frame_height_;
  float rotation_sensitivity_; //will result in half a round on a
  // retina sceen and one round on a normal screen when moving mouse from one
  // side to the other.

  int creature_type_; 

  float fitness_distance_forward_;
  float fitness_max_height_;
  float fitness_energy_;

  //std::vector<Creature> best_creatures_;
  Vec3 main_body_dim_;

  static SettingsManager* instance_;
};

#endif // SETTINGSMANAGER
