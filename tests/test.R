#---------------------------------------
# This script sets out to test the core
# functions of the tsCeatures package
#---------------------------------------

#----------------------------------------
# Author: Trent Henderson, 21 August 2021
#----------------------------------------

library(tsCeatures)

# Calculations

x <- rnorm(1000)
outs <- get_features(x)

# Feature list

View(feature_descriptions)
