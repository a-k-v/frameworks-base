/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AAPT_LINK_MANIFESTFIXER_H
#define AAPT_LINK_MANIFESTFIXER_H

#include "process/IResourceTableConsumer.h"
#include "util/Maybe.h"
#include "xml/XmlDom.h"

#include <string>

namespace aapt {

struct ManifestFixerOptions {
    Maybe<std::u16string> minSdkVersionDefault;
    Maybe<std::u16string> targetSdkVersionDefault;
    Maybe<std::u16string> renameManifestPackage;
    Maybe<std::u16string> renameInstrumentationTargetPackage;
    Maybe<std::u16string> versionNameDefault;
    Maybe<std::u16string> versionCodeDefault;
};

/**
 * Verifies that the manifest is correctly formed and inserts defaults
 * where specified with ManifestFixerOptions.
 */
struct ManifestFixer : public IXmlResourceConsumer {
    ManifestFixerOptions mOptions;

    ManifestFixer(const ManifestFixerOptions& options) : mOptions(options) {
    }

    bool consume(IAaptContext* context, xml::XmlResource* doc) override;
};

} // namespace aapt

#endif /* AAPT_LINK_MANIFESTFIXER_H */
