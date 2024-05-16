float detectFrequency(float targetFrequency) {
  float omega = (2.0 * PI * targetFrequency) / sampleRate;
  float sine = sin(omega);
  float cosine = cos(omega);
  float coeff = 2.0 * cosine;
  float q1 = 0, q2 = 0, q0;

  for (int i = 0; i < numSamples; i++) {
    q0 = coeff * q1 - q2 + (float)samples[i];
    q2 = q1;
    q1 = q0;
  }

  float magnitude = sqrt(q1 * q1 + q2 * q2 - q1 * q2 * coeff);
  return magnitude;
}
