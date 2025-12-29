import {useMDXComponents as getThemeComponents} from 'nextra-theme-docs';
import {Callout, FileTree} from "nextra/components";

import { Badge } from "components/ui/badge";

// Get the default MDX components
const themeComponents = getThemeComponents()

// Merge components
export function useMDXComponents() {
    return {
        ...themeComponents,
        Badge: Badge,
        Callout: Callout,
        FileTree: FileTree,
    }
}