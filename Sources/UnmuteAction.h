/* Copyright (c) 2019-present, Fred Emmott
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file.
 */
#pragma once

#include "BaseMuteAction.h"

class UnmuteAction final : public BaseMuteAction {
 public:
  UnmuteAction(
    ESDConnectionManager* esd,
    const std::string& context);
  static const std::string ACTION_ID;
  virtual std::string GetActionID() const override {
    return ACTION_ID;
  }

  static void PlayFeedbackSound();
 protected:
  virtual void MuteStateDidChange(bool isMuted) override;
  virtual void WillAppear() override;
  virtual void DoAction() override;
};
